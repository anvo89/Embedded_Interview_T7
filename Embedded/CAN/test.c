#include "stm32f103x.h"

#define SPEED_ID       0x101
#define ENGINE_POS_ID  0x102
#define ENGINE_TEMP_ID 0x103
#define OIL_PRESSURE_ID 0x104

void CAN_Config(void) {
    // Khởi tạo và cấu hình CAN ở đây...
    // Ví dụ: thiết lập mode, tốc độ, filter, ...
}

void UART_Config(void) {
    // Khởi tạo và cấu hình UART ở đây...
    // Ví dụ: thiết lập baud rate, data bits, stop bits, ...
}

void printMessage(const char *message) {
    while (*message) {
        // Gửi mỗi ký tự qua UART
        // Đảm bảo UART đã sẵn sàng trước khi gửi
        USART_SendData(USART1, *message++);
        while (!USART_GetFlagStatus(USART1, USART_FLAG_TXE));
    }
}

int main(void) {
    CAN_Config();
    UART_Config();

    while (1) {
        if (CAN_MessagePending(CAN1, CAN_FIFO0)) { 
            CanRxMsg RxMessage;
            CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);

            switch (RxMessage.StdId) {
                case SPEED_ID:
                    uint8_t speed = RxMessage.Data[0];
                    char speedMessage[50];
                    sprintf(speedMessage, "Tốc độ xe: %d km/h\n", speed);
                    printMessage(speedMessage);
                    break;

                case ENGINE_POS_ID:
                    uint16_t position = (RxMessage.Data[0] << 8) | RxMessage.Data[1];
                    float angle = (360.0 / 65535.0) * position;
                    char posMessage[50];
                    sprintf(posMessage, "Vị trí động cơ: %.2f độ\n", angle);
                    printMessage(posMessage);
                    break;

                case ENGINE_TEMP_ID:
                    int8_t raw_temp = RxMessage.Data[0];
                    int temperature = raw_temp - 40;
                    char tempMessage[50];
                    sprintf(tempMessage, "Nhiệt độ động cơ: %d°C\n", temperature);
                    printMessage(tempMessage);
                    break;

                case OIL_PRESSURE_ID:
                    uint16_t raw_pressure = (RxMessage.Data[0] << 8) | RxMessage.Data[1];
                    float pressure = raw_pressure * 0.01;
                    char pressureMessage[50];
                    sprintf(pressureMessage, "Áp suất dầu: %.2f kPa\n", pressure);
                    printMessage(pressureMessage);
                    break;
            }
        }
    }
}