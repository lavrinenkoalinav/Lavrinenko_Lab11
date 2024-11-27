#include <iostream>
#include <regex>
#include <string>
#include <Windows.h> 
using namespace std;

class File {
   
private:
    string fileName;
    string extension;
    size_t size;

public:

    File(const string& fileName, const string& extension, size_t size)
        : fileName(fileName), extension(extension), size(size) {}

    string getFileName() const {
        return fileName;
    }

    string getExtension() const {
        return extension;
    }

    size_t getSize() const {
        return size;
    }

    void setFileName(const string& fileName) {
        this->fileName = fileName;
    }

    void setExtension(const string& extension) {
        this->extension = extension;
    }

    void setSize(size_t size) {
        this->size = size;
    }

    string determineFileType() const {
        const regex imageRegex("(jpg|jpeg|png|gif|bmp|tiff)", regex::icase);
        const regex documentRegex("(doc|docx|pdf|txt|xls|xlsx|ppt|pptx)", regex::icase);
        const regex audioRegex("(mp3|wav|flac|aac)", regex::icase);
        const regex videoRegex("(mp4|mkv|avi|mov|wmv)", regex::icase);
        const regex archiveRegex("(zip|rar|7z|tar|gz)", regex::icase);

        if (regex_match(extension, imageRegex)) {
            return "Зображення";
        }
        if (regex_match(extension, documentRegex)) {
            return "Документ";
        }
        if (regex_match(extension, audioRegex)) {
            return "Аудіо";
        }
        if (regex_match(extension, videoRegex)) {
            return "Відео";
        }
        if (regex_match(extension, archiveRegex)) {
            return "Архів";
        }

        return "Невідомий тип";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    File file("Lavrinenko_Lab11", "pdf", 4096);

    cout << "Назва файлу: " << file.getFileName() <<endl;
    cout << "Розширення: " << file.getExtension() <<endl;
    cout << "Розмір: " << file.getSize() << " байтів" <<endl;
    cout << "Тип файлу: " << file.determineFileType() <<endl;

    return 0;
}
