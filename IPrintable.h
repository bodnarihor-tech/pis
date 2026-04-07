#ifndef IPRINTABLE_H
#define IPRINTABLE_H

class IPrintable {
public:
    // Чисто віртуальна функція (пункт №8)
    virtual void printTechnicalInfo() const = 0; 
    virtual ~IPrintable() = default;
};

#endif