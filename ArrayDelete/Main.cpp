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
                shiftCount++;
                break;
            }
        }

        if(i+shiftCount >= myArrayLen) {
            break; 
        }

        myArray[i] = myArray[i+shiftCount];

        if(!deleteElem) {
            i++;
        }
    }
}


void testDeleteFirstElementFromArray()
{
    int src[] = { 5, 6, 1, 3, 9 };
    int idxBuffer[] = { 0 };

    deleteMultipleFromArray(src, 5, idxBuffer, 1);

    assert(src[0] == 6);
    assert(src[1] == 1);
    assert(src[2] == 3);
    assert(src[3] == 9);
}

void testDeleteLastElementFromArray()
{
    int src[] = { 5, 6, 1, 3, 9 };
    int idxBuffer[] = { 4 };

    deleteMultipleFromArray(src, 5, idxBuffer, 1);

    assert(src[0] == 5);
    assert(src[1] == 6);
    assert(src[2] == 1);
    assert(src[3] == 3);
}

void testDeleteMiddleElementFromArray()
{
    int src[] = { 5, 6, 1, 3, 9 };
    int idxBuffer[] = { 2 };

    deleteMultipleFromArray(src, 5, idxBuffer, 1);

    assert(src[0] == 5);
    assert(src[1] == 6);
    assert(src[2] == 3);
    assert(src[3] == 9);
}

void testDeleteFirstTwoElementFromArray()
{
    int src[] = { 5, 6, 1, 3, 9 };
    int idxBuffer[] = { 0, 1 };

    deleteMultipleFromArray(src, 5, idxBuffer, 2);

    assert(src[0] == 1);
    assert(src[1] == 3);
    assert(src[2] == 9);
}

void testDeleteLastTwoElementFromArray()
{
    int src[] = { 5, 6, 1, 3, 9 };
    int idxBuffer[] = { 3, 4 };

    deleteMultipleFromArray(src, 5, idxBuffer, 2);

    assert(src[0] == 5);
    assert(src[1] == 6);
    assert(src[2] == 1);
}

void testDeleteMiddleTwoElementFromArray()
{
    int src[] = { 5, 6, 1, 3, 9 };
    int idxBuffer[] = { 1, 2 };

    deleteMultipleFromArray(src, 5, idxBuffer, 2);

    assert(src[0] == 5);
    assert(src[1] == 3);
    assert(src[2] == 9);
}

void testDeleteFirstAndLastElementFromArray()
{
    int src[] = { 5, 6, 1, 3, 9 };
    int idxBuffer[] = { 0, 4 };

    deleteMultipleFromArray(src, 5, idxBuffer, 2);

    assert(src[0] == 6);
    assert(src[1] == 1);
    assert(src[2] == 3);
}


void testDeleteNonEdgeConsecutiveElementFromArray()
{
    int src[] = { 5, 6, 1, 3, 9 };
    int idxBuffer[] = { 1, 3 };

    deleteMultipleFromArray(src, 5, idxBuffer, 2);

    assert(src[0] == 5);
    assert(src[1] == 1);
    assert(src[2] == 9);
}

void main()
{
    testDeleteFirstElementFromArray();
    testDeleteLastElementFromArray();
    testDeleteMiddleElementFromArray();

    testDeleteFirstTwoElementFromArray();
    testDeleteLastTwoElementFromArray();
    testDeleteMiddleTwoElementFromArray();

    testDeleteFirstAndLastElementFromArray();

    testDeleteNonEdgeConsecutiveElementFromArray();
}