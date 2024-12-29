#include <iostream>
#include <cstring>
#include <cstdlib> // Để sử dụng atoi

// Khai báo các biến cần dùng
int TIME_RED = 0, TIME_YELLOW = 0, TIME_GREEN = 0;
int status0 = 0;
const int INIT_BUTTON = 1;

int main()
{
    // Chuỗi buffer giả định được nhận
    char buffer[100] = "Set_up!10!5!15";

    // Kiểm tra chuỗi và xử lý
    if (strncmp(buffer, "Set_up!", 7) == 0)
    {                                      // So sánh 7 ký tự đầu tiên
        char *token = strtok(buffer, "!"); // Tách chuỗi dựa trên dấu "!"
        int index = 0;

        while (token != NULL)
        {
            if (index == 1)
                TIME_RED = atoi(token) * 1000; // Gán giá trị TIME_RED
            if (index == 2)
                TIME_YELLOW = atoi(token) * 1000; // Gán giá trị TIME_YELLOW
            if (index == 3)
                TIME_GREEN = atoi(token) * 1000; // Gán giá trị TIME_GREEN
            token = strtok(NULL, "!");           // Lấy token tiếp theo
            index++;
        }
        status0 = INIT_BUTTON; // Đặt trạng thái ban đầu
    }

    // Hiển thị kết quả để kiểm tra
    std::cout << "TIME_RED: " << TIME_RED << std::endl;
    std::cout << "TIME_YELLOW: " << TIME_YELLOW << std::endl;
    std::cout << "TIME_GREEN: " << TIME_GREEN << std::endl;
    std::cout << "Status: " << status0 << std::endl;

    return 0;
}
