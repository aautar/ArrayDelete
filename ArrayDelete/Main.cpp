#include <cstdio>
#include <cassert>

void deleteMultipleFromArray(int myArray[], int myArrayLen, int idxBuffer[], int idxBufferLen)
{
	int shiftCount = 0;
	int i = 0;

	while(true) {

		bool deleteElem = false;

		for(int j=0; j<idxBufferLen; j++) {
			if(i == (idxBuffer[j]-shiftCount)) {
				deleteElem = true;
				break;
			}
		}

		myArray[i] = myArray[i+shiftCount];
		if(i+shiftCount >= myArrayLen) {
			break; 
		}

		if(deleteElem) {
			shiftCount++;
			if(i+shiftCount < myArrayLen) {
				myArray[i] = myArray[i+shiftCount];
			}
		} else {
			i++;
		}
	}
}


void testDeleteFirstFromArray()
{
	int src[] = { 5, 6, 1, 3, 9 };
	int idxBuffer[] = { 0 };

	deleteMultipleFromArray(src, 10, idxBuffer, 1);

    assert();
}


void main()
{
	int myArray[10] = { 5, 6, 1, 3, 6, 8, 11, 35, 55, 83 };
	int idxBuffer[3] = { 0, 7, 9 };

	deleteMultipleFromArray(myArray, 10, idxBuffer, 3);
}