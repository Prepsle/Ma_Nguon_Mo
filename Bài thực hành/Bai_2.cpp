#include <iostream>
#include <vector>

//nhị phân đệ quy
int binarySearchRecursive(const std::vector<int>& arr, int target, int start, int end) {
    if (start > end) {
        return -1; // Không tìm thấy
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target) {
        // Tìm thấy giá trị, trả về vị trí
        return mid;
    } else if (arr[mid] > target) {
        // Tìm ở nửa trái
        return binarySearchRecursive(arr, target, start, mid - 1);
    } else {
        // Tìm ở nửa phải
        return binarySearchRecursive(arr, target, mid + 1, end);
    }
}

//nhị phân không đệ quy
int binarySearchIterative(const std::vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            // Tìm thấy giá trị, trả về vị trí
            return mid;
        } else if (arr[mid] > target) {
            // Tìm ở nửa trái
            end = mid - 1;
        } else {
            // Tìm ở nửa phải
            start = mid + 1;
        }
    }

    return -1; // Không tìm thấy
}

//tìm kiếm tuyến tính
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            // Tìm thấy giá trị, trả về vị trí
            return i;
        }
    }
    return -1; // Không tìm thấy
}

int main() {
    std::vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> unsortedArr = {3, 7, 1, 9, 5, 6};
    int target = 5;

    std::cout << "Nhi phan de quy: " << binarySearchRecursive(sortedArr, target, 0, sortedArr.size() - 1) << std::endl;
    std::cout << "Nhi phan khong de quy: " << binarySearchIterative(sortedArr, target) << std::endl;
    std::cout << "Tuyen tinh mang: " << linearSearch(unsortedArr, target) << std::endl;

    return 0;
}
