#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tìm giá trị lớn nhất trong mảng
int findMax(int arr[], int n, int *comparisonCount) {
    int max = arr[0];
    *comparisonCount = 0;

    for (int i = 1; i < n; i++) {
        (*comparisonCount)++;
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int n, int target, int *comparisonCount) {
    int left = 0;
    int right = n - 1;

    *comparisonCount = 0;

    while (left <= right) {
        (*comparisonCount)++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // Tìm thấy giá trị
        } else if (arr[mid] < target) {
            left = mid + 1;  // Tìm ở nửa phải
        } else {
            right = mid - 1;  // Tìm ở nửa trái
        }
    }

    return -1;  // Không tìm thấy
}

int main() {
    // Số phần tử trong mảng
    int n = 10000;

    // Khởi tạo mảng với các phần tử ngẫu nhiên
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    // Tìm MAX
    clock_t start_time = clock();
    int comparisonCountMax;
    int max = findMax(arr, n, &comparisonCountMax);
    clock_t end_time = clock();
    double executionTimeMax = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Tìm kiếm nhị phân
    int target = arr[rand() % n]; // Chọn một giá trị ngẫu nhiên để tìm kiếm
    clock_t start_time_binary_search = clock();
    int comparisonCountBinarySearch;
    int result = binarySearch(arr, n, target, &comparisonCountBinarySearch);
    clock_t end_time_binary_search = clock();
    double executionTimeBinarySearch = ((double)(end_time_binary_search - start_time_binary_search)) / CLOCKS_PER_SEC;

    // Ghi kết quả vào tệp tin
    FILE *file = fopen("result.txt", "w");
    if (file == NULL) {
        printf("Không thể mở tệp tin.\n");
        return 1;
    }

    fprintf(file, "Tim MAX:\n");
    fprintf(file, "Gia tri lon nhat: %d\n", max);
    fprintf(file, "So lan so sanh: %d\n", comparisonCountMax);
    fprintf(file, "Thoi gian thuc hien: %f seconds\n\n", executionTimeMax);

    fprintf(file, "Tim kiem nhi phan:\n");
    fprintf(file, "Gia tri can tim kiem: %d\n", target);
    fprintf(file, "Vi tri dau tien cua gia tri can tim kiem: %d\n", result);
    fprintf(file, "So lan so sanh: %d\n", comparisonCountBinarySearch);
    fprintf(file, "Thoi gian thuc hien: %f seconds\n", executionTimeBinarySearch);

    fclose(file);

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}
