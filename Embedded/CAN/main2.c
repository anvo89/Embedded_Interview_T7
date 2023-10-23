#define ENGINE_RPM_ID 0x0C2
#define ENGINE_TEMP_ID 0x0C3
#define ERROR_MSG_ID 0x1A1

/* Khởi tạo cấu trúc CAN */
CAN_HandleTypeDef hcan;

void CAN_Init(void) {
    /* Cấu hình Clock cho CAN */
    __HAL_RCC_CAN1_CLK_ENABLE();

    hcan.Instance = CAN1;
    hcan.Init.Prescaler = 10; // Điều chỉnh này dựa vào tần số Clock của STM32
    hcan.Init.Mode = CAN_MODE_NORMAL;
    hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
    hcan.Init.TimeSeg1 = CAN_BS1_3TQ;
    hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
    hcan.Init.TimeTriggeredMode = DISABLE;
    hcan.Init.AutoBusOff = DISABLE;
    hcan.Init.AutoWakeUp = DISABLE;
    hcan.Init.AutoRetransmission = ENABLE;
    hcan.Init.ReceiveFifoLocked = DISABLE;
    hcan.Init.TransmitFifoPriority = DISABLE;

    if (HAL_CAN_Init(&hcan) != HAL_OK) {
        // Error Handler
    }

    // Bật ngắt khi có tin nhắn mới trên bus CAN
    HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
    // Bắt đầu bus CAN
    HAL_CAN_Start(&hcan);
}

CAN_RxHeaderTypeDef RxHeader;
uint8_t rxData[8];

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
    // Đọc thông điệp từ bus CAN
    if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, rxData) == HAL_OK) {
        // Kiểm tra ID thông điệp hoặc trường dữ liệu nếu cần
        if (RxHeader.StdId == ID_MONG_MUON) { // ví dụ: ID_MONG_MUON là ID của thông điệp bạn muốn lọc
            // Ghi dữ liệu vào thẻ SD
            // Bạn sẽ cần sử dụng các hàm từ thư viện FATFS để mở, ghi và đóng file.
        }
    }
}

void monitorPerformance(void) {
    if (RxHeader.StdId == ENGINE_RPM_ID) {
        uint16_t engine_rpm = (rxData[0] << 8) + rxData[1]; // Giả sử RPM được mã hóa trong 2 byte đầu tiên
        // Ghi RPM vào SD Card
        writeDataToSDCard("RPM.txt", engine_rpm);
    }
    else if (RxHeader.StdId == ENGINE_TEMP_ID) {
        uint8_t engine_temp = rxData[0]; // Giả sử nhiệt độ động cơ nằm ở byte đầu tiên
        // Ghi nhiệt độ vào SD Card
        writeDataToSDCard("Temp.txt", engine_temp);
    }
}

void diagnoseErrors(void) {
    if (RxHeader.StdId == ERROR_MSG_ID) {
        // Ghi thông điệp lỗi vào SD Card
        writeDataToSDCard("Errors.txt", rxData);
    }
}

void researchCANMessages(void) {
    char filename[10];
    sprintf(filename, "%X.txt", RxHeader.StdId);
    writeDataToSDCard(filename, rxData);
}

void writeDataToSDCard(char *filename, uint8_t *data) {
    // Mở file
    // Ghi dữ liệu
    // Đóng file
    // Xử lý lỗi nếu cần
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
    if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, rxData) == HAL_OK) {
        monitorPerformance();
        diagnoseErrors();
        researchCANMessages();
    }
}


// Khai báo các hàm trước đó ở đây
void CAN_Init(void);
void SD_Card_Init(void); // Giả sử bạn có hàm này để khởi tạo thẻ SD
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void monitorPerformance(void);
void diagnoseErrors(void);
void researchCANMessages(void);

int main(void) {
    // Khởi tạo hệ thống
    HAL_Init();
    
    // Cấu hình Clock hệ thống (điều này phụ thuộc vào board và dòng STM32 bạn sử dụng)
    SystemClock_Config();
    
    // Khởi tạo CAN và SD Card
    CAN_Init();
    SD_Card_Init();

    while (1) {
        // Vì chúng ta đã sử dụng ngắt cho việc đọc thông điệp từ CAN, vòng lặp chính có thể trống hoặc
        // chứa các chức năng khác như cập nhật giao diện người dùng, đọc các cảm biến khác, v.v.
    }
}
