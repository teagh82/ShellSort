#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// 랜덤 함수를 이용하여 int 배열을 0~max-1의 값으로 무작위로 채우는 함수
static void initRandom( int list[], int n, int max=100 )
{
    for( int i=0 ; i<n ; i++ )
	list[i] = rand() % max;
}

// 배열을 화면에 보기 좋게 출력하는 함수. 디폴트 매개변수 사용
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

static void printStep( int arr[], int n, int c )
{
    printf("Step      %d = ", c);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

static void sortGapInsertion (int list[], int first, int last, int gap)
{
    int i, j, key;
    for( i=first+gap ; i<=last ; i=i+gap) { // 모든 요소에 대해서
	key = list[i];  			  // key 보관
	for( j=i-gap ; j>=first && key<list[j] ; j=j-gap ) // 왼쪽 요소와 비교 
	    list[j+gap]=list[j]; // key가 작으면 해당 요소 오른쪽으로 이동
	list[j+gap]=key; // key를 제 위치로 이동
    } 
}

void shell_sort ( int list[], int n )
{
    int i, gap, count=0;
    for( gap=n/2; gap>0; gap = gap/2 ) { // gap의 크기는 반씩 줄여 나간다.
		if( (gap%2) == 0 ) gap++;        // gap=4인 경우 gap=5로 5/4
		printf("-------------------------------------------------\n");
		printf("간격 = %d\n", gap);
		printf("-------------------------------------------------\n");
		for( i=0 ; i<gap ; i++ ) {
			sortGapInsertion( list, i, n-1, gap );
			printStep(list, n, i+1);
		}
		   printArray( list, 9, "sorted     " ); 
    }
}

void main()
{
	int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };	
	printArray( list, 9, "Original Data" );	// 정렬 전 배열 출력 
	shell_sort( list, 9 ); 		// 셸 정렬 실행 
	printf("-------------------------------------------------\n");
	printArray( list, 9, "Sorted Data" );	// 정렬 후 배열 출력 

	system("pause");
}