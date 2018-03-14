#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include "DataInterface.h"

namespace learn_data_structure
{
	typedef std::vector<IData*> DataList;
	class BinarySearch
	{
	public:
		BinarySearch(){};
		~BinarySearch(){};
		static bool SearchSafe(DataList& list, IData& key, size_t& index)
		{
			sort(list.begin(), list.end());
			return Search(list, key, index);
		}
		static bool Search(DataList& list, IData& key, size_t& index)
		{
			size_t num = list.size();
			size_t high = list.size() - 1;
			size_t low = 0;
			size_t mid = list.size() / 2;

			while ((*list[high] > *list[low]) || (*list[high] == *list[low]))
			{
				mid = (high + low) / 2;
				if (key > *list[mid])
				{
					low = mid + 1;
					
				}
				else if (key < *list[mid])
				{
					high = mid - 1;
				}
				else
				{
					index = mid;
					return true;
				}
			}
			return false;
		}
	};
}