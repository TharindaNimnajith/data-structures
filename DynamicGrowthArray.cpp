#include <iostream>

class DynamicGrowthArray {
private:
    int m_index;

    int m_max;

    int m_step;

    int *m_array;

public:
    DynamicGrowthArray(int size, int step);

    int getIndex() const;

    int getMax() const;

    void insert(int element);

    void remove(int index);

    void resize();

    void display();

    ~DynamicGrowthArray();
};

DynamicGrowthArray::DynamicGrowthArray(int size, int step) {
    m_array = new int[size];
    m_index = 0;
    m_max = size;
    m_step = step;
}

int DynamicGrowthArray::getIndex() const {
    return m_index;
}

int DynamicGrowthArray::getMax() const {
    return m_max;
}

void DynamicGrowthArray::insert(int element) {
    if (m_index >= m_max) {
        resize();
    }
    m_array[m_index] = element;
    m_index++;
}

void DynamicGrowthArray::remove(int index) {
    if (index > m_index || index < 0) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    for (int i = index; i <= m_index; i++) {
        m_array[i] = m_array[i + 1];
    }
    m_index--;
}

void DynamicGrowthArray::resize() {
    // m_max += m_step;
    // int* temp = new int[m_max];
    // for (int i = 0; i < m_index; i++)
    // {
    //     temp[i] = m_array[i];
    // }
    // delete[] m_array;
    // m_array = temp;

    int tempSize = m_max;
    m_max += m_step;
    int *tempArr = new int[m_max];
    memcpy(tempArr, m_array, tempSize * sizeof *m_array);
    delete[] m_array;
    m_array = tempArr;
}

void DynamicGrowthArray::display() {
    for (int i = 0; i < m_index; i++) {
        std::cout << m_array[i] << " ";
    }
    std::cout << std::endl;
}

DynamicGrowthArray::~DynamicGrowthArray() {
    delete[] m_array;
}

int main() {
    int size = 4;
    int resize = 2;

    DynamicGrowthArray dynamicGrowthArray(size, resize);

    dynamicGrowthArray.insert(10);
    dynamicGrowthArray.insert(20);
    dynamicGrowthArray.insert(30);
    dynamicGrowthArray.insert(40);
    dynamicGrowthArray.insert(50);
    dynamicGrowthArray.insert(60);

    dynamicGrowthArray.remove(3);

    dynamicGrowthArray.display();

    std::cout << dynamicGrowthArray.getIndex() << std::endl << dynamicGrowthArray.getMax();

    return 0;
}
