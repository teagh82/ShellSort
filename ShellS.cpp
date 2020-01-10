#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// ���� �Լ��� �̿��Ͽ� int �迭�� 0~max-1�� ������ �������� ä��� �Լ�
static void initRandom( int list[], int n, int max=100 )
{
    for( int i=0 ; i<n ; i++ )
	list[i] = rand() % max;
}

// �迭�� ȭ�鿡 ���� ���� ����ϴ� �Լ�. ����Ʈ �Ű����� ���
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
    for( i=first+gap ; i<=last ; i=i+gap) { // ��� ��ҿ� ���ؼ�
	key = list[i];  			  // key ����
	for( j=i-gap ; j>=first && key<list[j] ; j=j-gap ) // ���� ��ҿ� �� 
	    list[j+gap]=list[j]; // key�� ������ �ش� ��� ���������� �̵�
	list[j+gap]=key; // key�� �� ��ġ�� �̵�
    } 
}

void shell_sort ( int list[], int n )
{
    int i, gap, count=0;
    for( gap=n/2; gap>0; gap = gap/2 ) { // gap�� ũ��� �ݾ� �ٿ� ������.
		if( (gap%2) == 0 ) gap++;        // gap=4�� ��� gap=5�� 5/4
		printf("-------------------------------------------------\n");
		printf("���� = %d\n", gap);
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
	printArray( list, 9, "Original Data" );	// ���� �� �迭 ��� 
	shell_sort( list, 9 ); 		// �� ���� ���� 
	printf("-------------------------------------------------\n");
	printArray( list, 9, "Sorted Data" );	// ���� �� �迭 ��� 

	system("pause");
}