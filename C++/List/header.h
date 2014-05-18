class node;
class queue
{
        public:
                queue();
                ~queue();
                void add(int);
                int remove();
                bool empty();
        private:
                node *front,*rear;
};

class node
{
        private:
                int key;
                node *link;
                node(int); // Private constructor
                friend class queue;
};       
