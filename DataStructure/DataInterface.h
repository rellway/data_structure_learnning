#ifndef _DATA_INTERFACE_H_
#define _DATA_INTERFACE_H_
#include <iostream>
namespace learn_data_structure
{
	class IData
	{
	public:
		IData(){};
		virtual ~IData(){};
		virtual void* GetData() = 0;
		//virtual void* SetData(void* data) = 0;
		virtual void Print() = 0;
		virtual bool operator <(const IData& data) const = 0;
		virtual bool operator >(const IData& data) const = 0;
		virtual IData& operator =(const IData& data) = 0;
		virtual size_t Size() = 0;
	};
}
#endif