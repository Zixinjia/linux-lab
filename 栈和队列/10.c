void selection_sort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i; // 记录最小值的位置，第一个元素默认最小
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[min])
            {            // 找到目前最小值
                min = j; // 记录最小值的位置
            }
        }
        // 交换两个变量
        if (min != i)
        {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}