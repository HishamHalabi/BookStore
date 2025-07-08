class Custom_Exeption {
         string msg  ;
public:
          Custom_Exeption(const string& msg) {
                 this->msg = msg;
          }
          string getError()  {
                  return msg ;
          }
};
