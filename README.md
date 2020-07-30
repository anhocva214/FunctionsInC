# IDE
> Visual Studio

# THƯ VIỆN CẨN CÓ (BẮT BUỘC)
'''
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
'''

# NHỮNG HÀM ĐÃ ĐƯỢC XÂY DỰNG

> Mảng:

## *Hàm createArray1D_1*
'''
Tác dụng: trả về mảng 1 chiều với kích thước cho trước.
Cách dùng: createArray1D_1(kích thước mảng);
Lưu ý: dùng hàm fre( biến ) để giải phóng vùng nhớ (quan trọng)
Ví dụ:
    int* arr;
    arr = createArray1D_1(2);
    for (int i = 0; i < 2; i++) {
        printf("Nhap gia tri array[%d]: %d \n", i, arr[i]);
    }
    free(arr);
'''

## *Hàm createArray1D_2*
'''
Tác dụng: trả về mảng 1 chiều với kích thước là giá trị của array[0].
Cách dùng: createArray1D_2();
Lưu ý: 
    - dùng hàm fre( biến ) để giải phóng vùng nhớ (quan trọng)
    - SZIE_ARRAY_STRING = 100 (mặc định có thê chỉnh sửa)
Ví dụ:
    int* arrStr;
    arrStr = createArray1D_2();
    printf("Kich thuoc mang: %d \n", arrStr[0]);
    for (int i = 1; i < arrStr[0]; i++) {
        printf("arrStr[%d]: %d \n", i, arrStr[i]);
    }
    free(arrStr);
'''

## *Hàm printfArray*
'''
Tác dụng: in mảng 1 chiều (int) theo vị trí bắt đầu
Cách dùng: printArray(mảng cần in, kích thước mảng, vị trí bắt đầu);
Ví dụ:
	int arr[] = { 1,6,5,3,2 };
	printArray(arr, 5, 0);
'''

## *Hàm arraySort*
'''
Tác dụng: sắp xếp tăng hoặc giảm mảng 1 chiều ứng với cách tạo mảng 
Cách dùng:
	- arraySort(mảng cần sắp xếp, kích thước mảng , loại mảng khời tạo, kiểu sắp xếp mảng);
	- nếu mảng được khời tạo từ hàm createArray1D_1 thì loại mảng khởi tạo là 1
	- nếu mảng được khời tạo từ hàm createArray1D_2 thì loại mảng khởi tạo là 2
	- nếu kiểu sắp xếp mảng là true thì là loại sắp xếp tăng dần
	- nếu kiểu sắp xếp mảng là flase thì là loại sắp xếp giảm dần
Ví dụ:
	int arr[] = { 1,6,5,3,2 };
	arraySort(arr, 5, 1, true);
	printArray(arr, 5, 0);
'''

> Chuỗi:

## *Hàm emptyArrStr*
'''
Tác dụng: dùng để khởi tạo các giá trị rỗng cho mảng chuỗi.
Cách dùng: emptyArrStr(mảng chuỗi, kích thước mảng);
Lưu ý: độ dài chuỗi mặc định trong mảng là SZIE_ARRAY_STRING = 100;
Ví dụ:
    char test[70][100];
    emptyArrStr(test, 70);
'''
