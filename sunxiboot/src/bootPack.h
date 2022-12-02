#ifndef BOOTPACK_H
#define BOOTPACK_H

#include <QObject>

class bootPack : QObject{
   Q_OBJECT
private:
    typedef struct boot_head_t {
        quint32 instruction;
        quint8 magic[8];
        quint32 checksum;
        quint32 length;
        quint8 spl_signature[4];
        quint32 fel_script_address;
        quint32 fel_uenv_length;
        quint32 dt_name_offset;
        quint32 reserved1;
        quint32 boot_media;
        quint32 string_pool[13];
    } boot_head_t;

public:
    bootPack(QString _filePath, QString _saveFilePath, quint32 _paddingSize);

    ~bootPack();

private:
    [[nodiscard]] quint64 alignPadding(quint64 data) const;

private:
    QString filePath {};
    QString saveFilePath {};
    quint32 paddingSize = 0;
    quint64 fileSize = 0;
    quint32 sumData = 0;
    quint8 *fileData = nullptr;
};

#endif// BOOTPACK_H
