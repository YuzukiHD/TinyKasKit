#include "bootPack.h"

#include <utility>
#include <QFile>
#include <QMessageBox>

#include "x.h"

bootPack::bootPack(QString _filePath, QString _saveFilePath, quint32 _paddingSize) : filePath(std::move(_filePath)),
                                                                                     saveFilePath(std::move(_saveFilePath)),
                                                                                     paddingSize(_paddingSize) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        throw std::runtime_error("Can't open file");

    fileSize = file.size();
    auto fixedFileSize = alignPadding(fileSize);
    if (fixedFileSize < fileSize) {
        throw std::runtime_error("File size is too large");
    }
    if (fixedFileSize < sizeof(boot_head_t)) {
        throw std::runtime_error("File size is too small");
    }
    QByteArray fileByte = file.readAll();
    file.close();

    fileData = new quint8[fixedFileSize];
    std::memset(fileData, 0, fixedFileSize);
    std::memcpy(fileData, fileByte.data(), fileSize);

    auto *bootHead = reinterpret_cast<boot_head_t *>(fileData);
    auto *ptr = reinterpret_cast<quint32 *>(bootHead);
    auto length = le32_to_cpu(bootHead->length);

    bootHead->checksum = cpu_to_le32(0x5F0A6C39);
    bootHead->length = cpu_to_le32(alignPadding(length));
    length = bootHead->length;

    auto loopCount = length >> 2;
    if (fixedFileSize != length) {
        throw std::runtime_error("File format unexpected");
    }

    for (int i = 0; i < loopCount; ++i)
        sumData += le32_to_cpu(ptr[i]);
    bootHead->checksum = cpu_to_le32(sumData);

    QFile outFile(saveFilePath);
    if (!outFile.open(QIODevice::WriteOnly))
        throw std::runtime_error("Can't open file");
    outFile.write(reinterpret_cast<char *>(fileData), fixedFileSize);
    outFile.close();
}

bootPack::~bootPack() {
    delete[] fileData;
}

quint64 bootPack::alignPadding(quint64 data) const {
    return data + ((typeof(data)) (paddingSize) - 1) & ~((typeof(data)) (paddingSize) - 1);
}
