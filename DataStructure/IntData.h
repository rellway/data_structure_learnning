#ifndef _INT_DATA_H_
#define _INT_DATA_H_
#include <stdio.h>
#include "DataInterface.h"

namespace learn_data_structure
{
	class IntData : public IData
	{
	public:
		IntData(int data)
		{
			data_ = data;
		}
		virtual ~IntData(){};

		virtual void Print()
		{
			printf("%d", data_);
		}
		virtual void* GetData()
		{
			return &data_;
		}
		virtual int GetInt()
		{
			return data_;
		}
		virtual bool operator <(const IData& data) const
		{
			IntData intData = dynamic_cast<const IntData&>(data);
			return data_ < intData.GetInt();
		}
		virtual bool operator >(const IData& data) const
		{
			IntData intData = dynamic_cast<const IntData&>(data);
			return data_ > intData.GetInt();
		}
		virtual bool operator ==(const IData& data) const
		{
			IntData intData = dynamic_cast<const IntData&>(data);
			return intData.GetInt() == data_;
		}
		virtual IData& operator =(const IData& data)
		{
			IntData intData = dynamic_cast<const IntData&>(data);
			data_ = intData.GetInt();
			return *this;
		}
		virtual size_t Interpolation(const IData& high, const IData& low, size_t highIndex, size_t lowIndex)
		{
			IntData intHigh = dynamic_cast<const IntData&>(high);
			IntData intLow = dynamic_cast<const IntData&>(low);
			float ratio = ((float)(data_ - intLow.GetInt()) / (float)(intHigh.GetInt() - intLow.GetInt()));
			size_t add = (float)(highIndex - lowIndex) * ratio;
			return lowIndex + add;
		}
		virtual size_t Size()
		{
			return sizeof(IntData);
		}
	private:
		int data_;
	};
}
#endif