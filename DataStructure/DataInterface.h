#ifndef _DATA_INTERFACE_H_
#define _DATA_INTERFACE_H_
#include <iostream>
#include <vector>
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
		virtual bool operator ==(const IData& data) const = 0;
		virtual IData& operator =(const IData& data) = 0;
		virtual size_t Size() = 0;
		virtual size_t Interpolation(const IData& high, const IData& low, size_t highIndex, size_t lowIndex) = 0;
	};
	class IEnumData
	{
	public:
		IEnumData(){};
		virtual ~IEnumData(){};
		virtual IEnumData& operator =(const IEnumData& data) = 0;
		virtual size_t Number() = 0;
		virtual size_t Location() = 0;
		virtual void Print() = 0;
	};
	typedef std::vector<IEnumData*> Word;
	typedef std::vector<IEnumData*>::iterator WordIterator;
}
#endif