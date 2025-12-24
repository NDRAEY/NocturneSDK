void strtoupper(char* as){
    while(*as != 0)
    {
        if(*as >= 'a' && *as <= 'z')
            *as -= ('a' - 'A');
        as++;
    }
}