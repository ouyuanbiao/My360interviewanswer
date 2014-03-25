#include "ini_parser.h"


namespace qh
{
	qh::INIParser::INIParser(){};
	qh::INIParser::~INIParser(){};
	//! \brief 解析一个磁盘上的INI文件
	//! \param[in] - const std::string & ini_file_path
	//! \return - bool
	bool qh::INIParser::Parse(const std::string& ini_file_path){
		return false;
	};

	//! \brief 解析一段形如INI格式的内存数据。
	//!   例如：ini_data="a:1||b:2||c:3"
	//!         调用<code>Parse(ini_data, ini_data_len, "||", ":")</code>即可解析出这段数据。
	//!         解析完毕之后 
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
			const char* keystart = token.getCurReadPos();	//记录键值对起始位置
			bool Findkeyseperatro = false;
			while(!Findkeyseperatro && !token.isEnd()){
				if(token.current() == keyvalueseperator[0]){     //判断是否找到键值分隔符
					const char* keyseperatorcurpos = token.getCurReadPos();
					std::string keyseperatortemp = std::string(keyseperatorcurpos,len_keyseperator);
					if(strcmp(keyseperatortemp.data(),key_value_seperator.data()) == 0){
						Findkeyseperatro = true;
					};
				}
				else{
					if(token.current() == lineseperator[0]){     //如果没找到键值分割符，判断是否找到换行符
						const char* linecurpos = token.getCurReadPos();
						std::string linetemp = std::string(linecurpos,len_lineseperator);
						if(strcmp(linetemp.data(),line_seperator.data()) == 0){
							for(size_t i=0;i<len_lineseperator;i++)
								token.next();					//先找到换行符，跳过
						};
						keystart = token.getCurReadPos();		//更新键值对起始位置
					}
					else
						token.next();							//没找到键值分隔符和换行符，继续搜索
				}
			}
			if(!Findkeyseperatro)								//没有键值分隔符，则解析失败
				return false;
			const char* keyend = token.getCurReadPos();		
			//token.back(keyend-keystart);						//搜索到键值分隔符,回溯到键值起始位置
			key = std::string(keystart,keyend-keystart);        //记录键

			bool Findlineseprator = false;						//搜索键值分隔符后面的第一个换行符
			const char* linecurpos = token.getCurReadPos();
			while(!Findlineseprator && !token.isEnd()){
				if(token.current() == lineseperator[0]){        //判断是否找到换行符
					linecurpos = token.getCurReadPos();
					std::string lineseperatortemp = std::string(linecurpos,len_lineseperator);
					if(strcmp(lineseperatortemp.data(),line_seperator.data()) == 0){
						Findlineseprator = true;
					};
				}
				else
					token.next();
			}
			value = std::string(keyend+1,linecurpos-keyend-1);			//记录值
			keymap[key] = value;
			return true;
		}
	};

	//! \brief 从默认section中查找某个key，并返回找到的value。如果找不到，返回一个空串
	//! \param[in] - const std::string & key
	//! \param[in] - bool * found - 输出参数，true表明找到这个key
	//! \return - const std::string& - 返回的具体key对应的value
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