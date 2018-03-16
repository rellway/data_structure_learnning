#ifndef _INT_DATA_H_
#define _INT_DATA_H_
#include <stdio.h>
#include "DataInterface.h"

namespace learn_data_structure
{
	class CharData : public IEnumData
	{
	public:
		CharData(char data)
		{
			data_ = data;
		}
		virtual ~CharData(){};
		virtual IEnumData& operator =(const IEnumData& data)
		{
			CharData charData = dynamic_cast<const CharData&>(data);
			data_ = charData.GetChar();
			return *this;
		}
		virtual size_t Number()
		{
			return 26;
		}
		virtual size_t Location()
		{
			if (data_ > 'a')
				return data_ - 'a';
			else
				return 0;
		}
		char GetChar()
		{
			return data_;
		}
		virtual void Print()
		{
			printf("%c", data_);
		}
	private:
		char data_;
	};
	class CharWord
	{
	public:
		CharWord(std::string word)
		{
			
			for (size_t i = 0; i < word.length();  ++i)
			{
				CharData* charData = new CharData(word[i]);
				word_.push_back(charData);
			}
		}
		~CharWord()
		{
			for (size_t i = 0; i < word_.size(); ++i)
			{
				delete word_[i];
			}
		}
		Word* GetWord()
		{
			return &word_;
		}
	private:
		Word word_;
	};
}
#endif