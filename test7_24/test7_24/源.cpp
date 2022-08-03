//#include<iostream>
//#include<fstream>
//using namespace std;
//template<class T>
//T my_arr(const T arr[])
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[0] < arr[i])
//		{
//			arr[0] = arr[i];
//		}
//	}
//	return arr[0];
//}
//int main()
//{
//	int arr1[] = {11,22,33,44,55,66,77,88,99,1010}; 
//	double arr2[] = { 11.1,22.2,33.3,44.4,55.5,66.6,77.7,88.8,99.9,100.10 };
//	cout << my_arr(arr1[]) << endl;
//	cout << my_arr(arr2[]) << endl;
//}
#include<iostream>
#include<cmath>
using namespace std;
template <class T>T getmax(T a[]) {
    for (int i = 0; i < 10; i++) {
        if (a[0] < a[i]) {
            a[0] = a[i];
        }
    }
    return a[0];
}
int main() {
    int int_array[] = { 11,22,33,44,55,66,77,88,99,1010 };
    double double_array[] = { 11.1,22.2,33.3,44.4,55.5,66.6,77.7,88.8,99.9,100.10 };
    cout << "The int_max is " << getmax(int_array) << endl;
    cout << "The double_max is " << getmax(double_array) << endl;
}