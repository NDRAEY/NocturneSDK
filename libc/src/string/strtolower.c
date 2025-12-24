void strtolower(char* as){
    while(*as != 0)
    {
        if(*as >= 'A' && *as <= 'Z')
            *as += ('a' - 'A');
        as++;
    }
}