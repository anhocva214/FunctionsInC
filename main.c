#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// VARIABLE GLOBAL
const int SZIE_ARRAY_STRING = 100;
// END VARIABLE GLOBAL

// STRING

void emptyArrStr(char str[][SZIE_ARRAY_STRING], int size) {
	for (int i = 0; i < size; i++) {
		str[i][0] = '\0';
	}
}

int lenArrStr(char str[][SZIE_ARRAY_STRING]) {
	int count = 0, index = 0;
	while (true) {
		if (strlen(str[index]) != 0) {
			count++;
			index++;
		}
		else {
			return count;
		}
	}
}

int strFind(char str[], char text[]) {
	int count = 0, index = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (count == strlen(text)) {
			return i - 1;
		}
		else if (str[i] == text[index]) {
			/*printf("%d ", i);
			printf("%d\n", count);*/
			count++;
			index++;
			if (count == strlen(text)) {
				return i - strlen(text) + 1;
			}
		}
		else {
			count = 0;
			index = 0;
		}
	}
	return -1;
}

void strSlice(char strcut[], char str[], int start, int end) {
	int index = 0;
	for (int i = start; i <= end; i++) {
		strcut[index] = str[i];
		index++;
	}
	strcut[index] = '\0';
	//printf("strCut:  %s \n", strcut);
}

void strSerial(char str[], char strA[], char strB[]) {
	int index = 0;
	for (int i = 0; i < strlen(strA); i++) {
		str[index] = strA[i];
		index++;
	}
	for (int i = 0; i < strlen(strB); i++) {
		str[index] = strB[i];
		index++;
	}
	str[index] = '\0';
}

void strSplit(char arrayStr[][SZIE_ARRAY_STRING], char str[], char temp[]) {
	//strcpy_s(arrayStr[0], "anho");
	int index = 0;
	while (true) {
		int x = strFind(str, temp);
		if (x == -1) {
			strcpy_s(arrayStr[index], str);
			break;
		}
		char text[100];
		strSlice(text, str, 0, x - 1);
		strcpy_s(arrayStr[index], text);
		strSlice(str, str, x + strlen(temp), strlen(str) - 1);
		/*printf("\ntext : %s", text);
		printf("\nstr : %s", str);*/
		index++;
	}
}

// END STRING

// ARRAY

int* createArray1D_1(int n) {
	static int* array = (int*)malloc(n * sizeof(int));
	int x;
	for (int i = 0; i < n; i++) {
		printf("Nhap gia tri array[%d]: ", i);
		scanf_s("%d", &x);
		array[i] = x;
	}
	return array;
}

int* createArray1D_2() {
	printf("nhap mang: ");
	char strArr[SZIE_ARRAY_STRING];
	gets_s(strArr);
	//printf("%s", strArr); 

	char arrStr[SZIE_ARRAY_STRING][SZIE_ARRAY_STRING];
	emptyArrStr(arrStr, SZIE_ARRAY_STRING);
	char temp[] = " ";
	strSplit(arrStr, strArr, temp);
	int size = lenArrStr(arrStr);
	static int* array = (int*)malloc((size+1) * sizeof(int));
	array[0] = size+1;
	for (int i = 1; i <= size; i++) {
		int x = atoi(arrStr[i-1]);
		array[i] = x;

	}
	return array;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void arraySort(int array[], int size, int typeArr, int typeSort) {
	int i;
	if (typeArr == 1) {
		i = 0;
		size = size - 1;
	}
	else {
		i = 1;
	}
	for (i; i < size; i++) {
		for (int j = i + 1; j <= size; j++) {
			if (typeSort == false) {
				if (array[j] > array[i]) {
					swap(&array[j], &array[i]);
				}
			}
			else {
				if (array[j] < array[i]) {
					swap(&array[j], &array[i]);
				}
			}
		}
	}
}

void printArray(int array[], int size, int start) {

	//printf("%d", *((&array + 1) - array)/sizeof(*array));
	for (int i = start; i < size; i++) {
		printf("[%d]: %d \n", i, array[i]);
	}
}

// END ARRAY

int main() {

	/*
	  Hàm arraySort
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
	 */

	/*
	  Hàm printfArray
	  Tác dụng: in mảng 1 chiều (int) theo vị trí bắt đầu
	  Cách dùng: printArray(mảng cần in, kích thước mảng, vị trí bắt đầu);
	  Ví dụ:
			int arr[] = { 1,6,5,3,2 };
			printArray(arr, 5, 0);
	 */

	/*
	  Hàm createArray1D_2
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
	 */

	/*
	  Hàm createArray1D_1
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
	 */

	 /*
	  Hàm emptyArrStr
	  Tác dụng: dùng để khởi tạo các giá trị rỗng cho mảng chuỗi.
	  Cách dùng: emptyArrStr(mảng chuỗi, kích thước mảng);
	  Lưu ý: độ dài chuỗi mặc định trong mảng là SZIE_ARRAY_STRING = 100;
	  Ví dụ:
		  char test[70][100];
		  emptyArrStr(test, 70);
	  */

	  /*
	  Hàm lenArrStr
	  Tác dụng: trả về kích thước của mảng chuỗi
	  Cách dùng:
		  - dùng hàm emptyArrStr
		  - sau đó mới dùng lenArrStr(mảng chuỗi);
	  Lưu ý: độ dài chuỗi mặc định trong mảng là SZIE_ARRAY_STRING = 100;
	  Ví dụ:
		  char test[70][100];
		  emptyArrStr(result, 70);
		  test[0] <-- "text1"
		  test[1] <-- "text2"
		  test[2] <-- "text3"
		  printf("lenght: %d", lenArrStr(test)); --> length: 3
	  */

	  /*
	  Hàn strFind
	  Tác dụng: trả về vị trí đầu tiền của chuỗi s2 trong chuỗi s1
	  Cách dùng: strFind(chuỗi s1, chuỗi s2);
	  Ví dụ:
		  char s1[]="tackecon";
		  char s2[]="ke";
		  printf("Vị trí: %d", strFind(s1, s2)) --> Vị trí: 3
	  */

	  /*
	  Hàn strSlice
	  Tác dụng: cắt và gán chuỗi s1 cho chuỗi s2
	  Cách dùng: strSlice(s2, s1, start, end);
	  Lưu ý:
		  - start : vị trí bắt đầu
		  - end : vị trí kết thúc
	  Ví dụ:
		  char s1[]="tackecon";
		  char s2[100];
		  strSlice(s2, s1, 2, 4);
		  printf("s2: %s", s2); --> s2: cke
	  */

	  /*
	  Hàn strSerial
	  Tác dụng: nối chuỗi s1 và chuỗi s2 và gán cho chuỗi s3
	  Cách dùng: strSlice(s3, s1, s2);
	  Lưu ý: kích thước của chuỗi s3 > độ dài thực của chuỗi s1 + độ dài thực của chuỗi s2
	  Ví dụ:
			char s1[100];
			s1 = "tacke"; --> độ dài thực của chuỗi s1 là 5
			char s2[100];
			s2 = "con"; --> dộ dài thực của chuỗi s2 là 3
			char s3[100]; --> kích thước của chuỗi s1 là 100 > 5 + 3
			strSerial(s3, s1, s2);
			printf("ss: %s", s3); --> s3: tackecon
	  */

	  /*
	  Hàn strSplit
	  Tác dụng: tách chuỗi s1 thành các chuỗi con theo chuỗi s2 và gán các chuỗi con vào mảng chuỗi arrayStr
	  Cách dùng:
			- dùng hàm emptyArrStr
			- strSplit(arrayStr, s1, s2);
	  Lưu ý: kích thước của chuỗi s3 > độ dài thực của chuỗi s1 + độ dài thực của chuỗi s2
	  Ví dụ:
			char array[100][100];
			emptyArrStr(array, 100); --> khởi tạo mảng rỗng cho mảng chuỗi
			char str[] = "tackecon";
			char text[] = "ke";

			strSplit(array, str, text);

			for (int i = 0; i < lenArrStr(array); i++) { --> in các giá trị có trong mảng chuỗi
				printf("%s\n", array[i]);
			}
	  */



	return 0;
}