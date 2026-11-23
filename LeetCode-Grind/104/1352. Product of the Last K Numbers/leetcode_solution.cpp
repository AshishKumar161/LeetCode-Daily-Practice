class ProductOfNumbers {
    private : 
    vector < int > temp ;
    
    public:
    
        ProductOfNumbers() 
        {
            temp.push_back(1) ;
        }
        
        void add(int nums) 
        {
            if (nums == 0)
            {
                temp.clear() ;
                temp.push_back(1) ;
            }      
            
            else 
            {
                int product = temp.back() * nums ;
                temp.push_back(product) ;
            }
        }
        
        int getProduct(int k) 
        {
            int n = temp.size() ;
    
            if (k >= n)
            {
                return 0 ;
            }    
    
            return temp[n - 1] / temp[n - k - 1] ;
        }
    };
