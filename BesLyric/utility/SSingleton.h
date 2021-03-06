/**
* Copyright (C) 2014-2050 
* All rights reserved.
* 
* @file       Singleton.h
* @brief      
* @version    v1.0      
* @author     SOUI group   
* @date       2014/08/02
* 
* Describe    SOUI系统中使用的单件模块
*/

#pragma once

#include <assert.h>

namespace SOUI
{

    /**
    * @class      Singleton
    * @brief      单件模板
    * 
    * Describe    
    */
    template <typename T> 
    class Singleton
    {
    protected:
        static    T* ms_Singleton;

    public:
        Singleton( void )
        {
            assert( !ms_Singleton );
            ms_Singleton = static_cast<T*>(this);
        }
        virtual ~Singleton( void )
        {
            assert( ms_Singleton );
            ms_Singleton = 0;
        }
        static T& getSingleton( void )
        {
			if(ms_Singleton)
				return *ms_Singleton;
			else
				ms_Singleton = new (T);

            return ( *ms_Singleton );
        }
        static T* getSingletonPtr( void )
        {
            return ( ms_Singleton );
        }

    private:
        Singleton& operator=(const Singleton&)
        {
            return *this;
        }
        Singleton(const Singleton&) {}
    };

	template <typename T> T* Singleton<T>::ms_Singleton = NULL;

}//namespace SOUI