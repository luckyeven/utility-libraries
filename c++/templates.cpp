template<typename... Args>
void print(Args... args)
{
    std::initializer_list<int>{([&]{cout << args << endl; }(), 0)...};
}