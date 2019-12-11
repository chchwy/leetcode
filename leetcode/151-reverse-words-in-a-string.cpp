class Solution 
{
public:
    void reverseWords(string &s)
    {
        std::istringstream sin( s );
        std::vector< std::string > s_pool;
        while ( sin >> s )
        {
            s_pool.push_back( s );
        }
        
        std::ostringstream sout;
        for ( int i = s_pool.size() - 1 ; i >= 0; --i )
        {
            sout << s_pool[ i ];
            if ( i != 0 )
            {
                sout << " ";
            }
        }
        s = sout.str();
    }
};