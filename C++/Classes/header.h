class Person
{
        public:
                Person();
                Person(char *,int);
                Person(const Person &); // Copy constructor
                ~Person();
                Person& operator=(const Person &);
                void read();
                void write() const;
                friend void dosth(Person &); // friend function
        private:
                //char name[6];
                char *name;
                int age;
};
