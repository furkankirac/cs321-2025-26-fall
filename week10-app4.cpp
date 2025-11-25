// ConditionalType

// struct ABC {
//     using type = int;
// };


int main(int argc, char* argv[])
{
    // ConditionalType<int, float, true>::type; // --> int
    // ConditionalType<int, float, false>::type; // --> float

    return 0;
}
