#include <windows.h>
#include <iostream>

int main() {
    PRINTER_INFO_2* pPrinterInfo;
    DWORD dwNeeded, dwReturned;
    EnumPrinters(PRINTER_ENUM_LOCAL, nullptr, 2, nullptr, 0, &dwNeeded, &dwReturned);
    pPrinterInfo = (PRINTER_INFO_2*)malloc(dwNeeded);
    if (!pPrinterInfo) {
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }
    if (EnumPrinters(PRINTER_ENUM_LOCAL, nullptr, 2, (LPBYTE)pPrinterInfo, dwNeeded, &dwNeeded, &dwReturned)) {
        for (DWORD i = 0; i < dwReturned; i++) {
            std::cout << "Printer Name: " << pPrinterInfo[i].pPrinterName << std::endl;
            std::cout << "Port Name: " << pPrinterInfo[i].pPortName << std::endl;
            // You can access more properties like DriverName, Location, etc., as needed.
            std::cout << std::endl;
        }
    } else {
        std::cerr << "EnumPrinters failed" << std::endl;
    }
    free(pPrinterInfo);

    return 0;
}
