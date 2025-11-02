#include <stdio.h>
#include <stdlib.h>

// ================= Insertion Sort ==================
void insertionSort(int a[], int n)
{
    int i, j, x;
    for(i=1; i<n; i++)
    {
        x = a[i];
        j = i-1;
        while(j>=0 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

// =============== Binary Insertion Sort ==============
int binarySearch(int a[], int item, int low, int high)
{
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(item < a[mid]) high = mid-1;
        else low = mid+1;
    }
    return low;
}

void binaryInsertionSort(int a[], int n)
{
    int i, j, pos, x;
    for(i=1; i<n; i++)
    {
        x = a[i];
        pos = binarySearch(a, x, 0, i-1);
        for(j=i-1; j>=pos; j--) a[j+1] = a[j];
        a[pos] = x;
    }
}

// ================= Shaker Sort ======================
void shakerSort(int a[], int n)
{
    int left = 0, right = n-1, k = 0;
    while(left < right)
    {
        for(int i=left; i<right; i++)
            if(a[i] > a[i+1])
            {
                int t=a[i]; a[i]=a[i+1]; a[i+1]=t;
                k = i;
            }
        right = k;

        for(int i=right; i>left; i--)
            if(a[i] < a[i-1])
            {
                int t=a[i]; a[i]=a[i-1]; a[i-1]=t;
                k = i;
            }
        left = k;
    }
}

// ============ PRINT ARRAY ===========================
void printArray(int a[], int n)
{
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}

// =================== MAIN ===========================
int main()
{
    int n, i;
    printf("Nhap so phan tu: "); scanf("%d", &n);

    int *A = (int*)malloc(n*sizeof(int));
    int *B = (int*)malloc(n*sizeof(int));
    int *C = (int*)malloc(n*sizeof(int));

    printf("Nhap mang: \n");
    for(i=0;i<n;i++) scanf("%d",&A[i]);

    // copy ra 3 m?ng
    for(i=0;i<n;i++) B[i] = C[i] = A[i];

    insertionSort(A,n);
    binaryInsertionSort(B,n);
    shakerSort(C,n);

    printf("\nSau khi sort (Insertion): "); printArray(A,n);
    printf("Sau khi sort (Binary Insertion): "); printArray(B,n);
    printf("Sau khi sort (Shaker Sort): "); printArray(C,n);

    free(A); free(B); free(C);
    return 0;
}

