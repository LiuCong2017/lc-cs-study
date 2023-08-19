//
// Created by X130 on 2023/8/4.
//
#include <iostream>

using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        //设置随机数据进入数组
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        //进行排序
        for (int i = 0; i < n; i++) {
            //第一趟 i=0 不比较
            if (i == 0) {
                print(arr, n);
                continue;
            }
            //假设前面已经排好i个数据

            for (int j = i; j > 0; j--) {
                // 比较的值是 arr[j] 和 arr[j-1]比较
                if (arr[j - 1] > arr[j]) {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
            if (i == 1) {
                //第二趟
                print(arr, n);
            }

        }
        print(arr, n);

    }
    return 0;
}