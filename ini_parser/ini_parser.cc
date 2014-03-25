#include "ini_parser.h"


namespace qh
{
	qh::INIParser::INIParser(){};
	qh::INIParser::~INIParser(){};
	//! \brief ����һ�������ϵ�INI�ļ�
	//! \param[in] - const std::string & ini_file_path
	//! \return - bool
	bool qh::INIParser::Parse(const std::string& ini_file_path){
		return false;
	};

	//! \brief ����һ������INI��ʽ���ڴ����ݡ�
	//!   ���磺ini_data="a:1||b:2||c:3"
	//!         ����<code>Parse(ini_data, ini_data_len, "||", ":")</code>���ɽ�����������ݡ�
	//!         �������֮�� 
	//!         Get("a")=="1" && Get("b")=="2" && Get("c")=="3"
	//! \param[in] - const char * ini_data
	//! \param[in] - size_t ini_data
	//! \param[in] - const std::string & line_seperator
	//! \param[in] - const std::string & key_value_seperator
	//! \return - bool
	bool qh::INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator , const std::string& key_value_seperator ){
		std::string key;
		std::string value;
		Tokener token(ini_data);
		size_t len_lineseperator = line_seperator.size();
		size_t len_keyseperator = key_value_seperator.size();
		const char* lineseperator = line_seperator.data();
		const char* keyvalueseperator = line_seperator.data();
		while(!token.isEnd()){
			const char* keystart = token.getCurReadPos();	//��¼��ֵ����ʼλ��
			bool Findkeyseperatro = false;
			while(!Findkeyseperatro && !token.isEnd()){
				if(token.current() == keyvalueseperator[0]){     //�ж��Ƿ��ҵ���ֵ�ָ���
					const char* keyseperatorcurpos = token.getCurReadPos();
					std::string keyseperatortemp = std::string(keyseperatorcurpos,len_keyseperator);
					if(strcmp(keyseperatortemp.data(),key_value_seperator.data()) == 0){
						Findkeyseperatro = true;
					};
				}
				else{
					if(token.current() == lineseperator[0]){     //���û�ҵ���ֵ�ָ�����ж��Ƿ��ҵ����з�
						const char* linecurpos = token.getCurReadPos();
						std::string linetemp = std::string(linecurpos,len_lineseperator);
						if(strcmp(linetemp.data(),line_seperator.data()) == 0){
							for(size_t i=0;i<len_lineseperator;i++)
								token.next();					//���ҵ����з�������
						};
						keystart = token.getCurReadPos();		//���¼�ֵ����ʼλ��
					}
					else
						token.next();							//û�ҵ���ֵ�ָ����ͻ��з�����������
				}
			}
			if(!Findkeyseperatro)								//û�м�ֵ�ָ����������ʧ��
				return false;
			const char* keyend = token.getCurReadPos();		
			//token.back(keyend-keystart);						//��������ֵ�ָ���,���ݵ���ֵ��ʼλ��
			key = std::string(keystart,keyend-keystart);        //��¼��

			bool Findlineseprator = false;						//������ֵ�ָ�������ĵ�һ�����з�
			const char* linecurpos = token.getCurReadPos();
			while(!Findlineseprator && !token.isEnd()){
				if(token.current() == lineseperator[0]){        //�ж��Ƿ��ҵ����з�
					linecurpos = token.getCurReadPos();
					std::string lineseperatortemp = std::string(linecurpos,len_lineseperator);
					if(strcmp(lineseperatortemp.data(),line_seperator.data()) == 0){
						Findlineseprator = true;
					};
				}
				else
					token.next();
			}
			value = std::string(keyend+1,linecurpos-keyend-1);			//��¼ֵ
			keymap[key] = value;
			return true;
		}
	};

	//! \brief ��Ĭ��section�в���ĳ��key���������ҵ���value������Ҳ���������һ���մ�
	//! \param[in] - const std::string & key
	//! \param[in] - bool * found - ���������true�����ҵ����key
	//! \return - const std::string& - ���صľ���key��Ӧ��value
	const std::string& qh::INIParser::Get(const std::string& key, bool* found){
		
		*found = true;
		return keymap[key];
		
		*found = false;
		return NULL;
	};

	const std::string& qh::INIParser::Get(const std::string& section, const std::string& key, bool* found){
		SectionMap::iterator itSection = sectionmap.find(section);
		if(sectionmap.end() != itSection){
			KeyMap::iterator itKey = itSection->second.find(key);
			if(itKey != itSection->second.end()){
				return itKey->second.c_str();
				*found = true;
			}
		}
		*found = false;
		return NULL;
	};
}