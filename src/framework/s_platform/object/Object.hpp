#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object
{
  public:
    static long int NextSeqNo;

    Object();
    Object(const Object&);
    Object(Object&&) noexcept;
    Object& operator=(const Object&);
    Object& operator=(Object&&) noexcept;
    virtual ~Object();

    long int SeqNo() const;

  private:
    long int _seq_no = 0;
};

#endif