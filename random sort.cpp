//随机快排
#include <iostream>
using namespace std;

void quicksort(int a[], int l, int r)
{
    if (l >= r) return; //递归结束条件
    int low = l, high = r; //定义两个下标指针
    int tmp; //用来交换
    int pos = rand()%(r - l) + l + 1; //随机中间轴
    int k = a[pos];//记录轴位置的元素值
    while (low < high)
    {
        while (a[low] < k)  low++; //寻找轴左侧第一个不比轴元素小的数
        while (a[high] > k) high--; //寻找轴右侧第一个不比轴元素大的数
        if (low <= high)//如果找到了这样两个数，就交换这两个数的位置
        {
            tmp = a[low];
            a[low] = a[high];
            a[high] = tmp;
            low++; high--;
        }
    }
    //此时pos位置的元素已经在正确位置，只需要递归地排序左边和右边的部分即可
    //注意，此时low和high已经交错过，故应该是l-high和low-r
    quicksort(a, l, high);
    quicksort(a, low, r);
}

int main()
{
    int a[1000];
    for (int i = 0; i < 1000; i++)
        a[i] = 1000 - i;
    quicksort(a, 0, 999);
    for (int i = 0; i < 1000; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
