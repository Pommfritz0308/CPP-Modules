#include "Serializer.hpp"
#include "Data.hpp"

int main (void)
{
    Data *data = new Data();
    std::cout << "Original address: " << data << std::endl;
    uintptr_t i = Serializer::serialize(data);
    std::cout << "Address after serialization: "
                << Serializer::deserialize(i) << std::endl;
    delete data;
}