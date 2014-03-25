#include "qh_string.h"

#include <string.h>
#include <stdio.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
		if (s == NULL){
			data_ = NULL;
            len_ = 0;
        }
        else{
            size_t len =  strlen(s);
            data_ = new char[len + 1];
			if(!data_){
				fprintf(stderr, "Memory Alloc Error!\n" );
				exit(1);
			}
            strcpy(data_, s);
            len_ = len;
        }
    }

    string::string( const char* s, size_t len )
    {
		if (s != NULL && len!=0){
            size_t strLen = strlen(s);
            len = (len > strLen) ? strLen : len;
            data_ = new char[len + 1];
			if(!data_){
				fprintf(stderr, "Memory Alloc Error!\n" );
				exit(1);
			}
            strncpy(data_, s, len);
            data_[len] = '\0';
            len_ = len;
        }
		else{
			data_ = NULL;
			len_ = 0;
		}
    }

    string::string( const string& rhs )
    {
		size_t len = rhs.size();
        data_ =  new char[len + 1];
		if(!data_){
			fprintf(stderr, "Memory Alloc Error!\n" );
			exit(1);
		}
        strcpy(data_, rhs.data_);
        len_ = len;
    }

    string& string::operator=( const string& rhs )
    {
		if (this == &rhs){
            return *this;
        }

        if (data_ != NULL){
            delete [] data_;
			data_ = NULL;
        }
        size_t len = rhs.size();
        data_ = new char[len + 1];
		if(!data_){
			fprintf(stderr, "Memory Alloc Error!\n" );
			exit(1);
		}
        strcpy(data_, rhs.data_);
        len_ = len;
        return *this;
    }

    string::~string()
    {
		if (data_ != NULL){
            delete [] data_;
            data_ = NULL;
            len_ = 0;
        }
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
		if(data_ != NULL){
			char*  data = new char[len_];
			if(!data){
				fprintf(stderr, "Memory Alloc Error!\n" );
				exit(1);
			}
			strncpy(data, data_, len_);
			return data;
		}
		else
			return NULL;
    }

    const char* string::c_str() const
    {
		return data_;
    }

    char* string::operator[]( size_t index )	//取值或修改
    {
        if (index >= len_ && index<0){
            printf("%s", "Index Input Error!\n" );
            return NULL;
        }
        return &data_[index];
    }
    
}
