#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
class BadFileException: public exception{
    virtual const char* what() const throw()
      {
        return "Bad File.";
      }
};
#endif // EXCEPTIONS_H
