#include <iostream>
#include <string>

using namespace std;

class Device 
{
public:
    virtual string GetInfo() const = 0;
    virtual ~Device() {}
};

class VideoCard : public Device 
{
public:
    string GetInfo() const override 
    {
        return "Видеокарта: RTX 3080";
    }
};

class Processor : public Device 
{
public:
    string GetInfo() const override 
    {
        return "Процессор: М1 Pro";
    }
};

class HardDrive : public Device
{
public:
    string GetInfo() const override 
    {
        return "Жесткий диск: SSD 1TB NVMe";
    }
};


class Report 
{
protected:
    Device* device;
public:
    Report(Device* dev) : device(dev) {}
    virtual void Show() const = 0;
    virtual ~Report() {}
};

class TextReport : public Report 
{
public:
    TextReport(Device* dev) : Report(dev) {}

    void Show() const override
    {
        cout << "отчёт устройства: " << endl;
        cout << device->GetInfo() << endl;
    }
};

int main() 
{
    VideoCard videoCard;
    Processor processor;
    HardDrive hardDrive;


    TextReport report1(&videoCard);
    report1.Show();

    TextReport report2(&processor);
    report2.Show();

    TextReport report3(&hardDrive);
    report3.Show();

    return 0;
}