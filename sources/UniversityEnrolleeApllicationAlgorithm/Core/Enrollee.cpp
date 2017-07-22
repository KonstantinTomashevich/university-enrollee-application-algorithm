#include "Enrollee.hpp"
#include <algorithm>

namespace UniversityEnrolleeApllicationAlgorithm
{
Enrollee::Enrollee () :
    ReferenceCounted (),
    passportSeries_ (),
    passportNumber_ (),

    examsResults_ (),
    currentChoiseIndex_ (0),
    choises_ (0)
{

}

Enrollee::~Enrollee ()
{

}

std::string Enrollee::GetPassportSeries () const
{
    return passportSeries_;
}

void Enrollee::SetPasportSeries (const std::string &passportSeries)
{
    passportSeries_ = passportSeries;
}

std::string Enrollee::GetPassportNumber() const
{
    return passportNumber_;
}

void Enrollee::SetPasportNumber (const std::string &passportNumber)
{
    passportNumber_ = passportNumber;
}

unsigned Enrollee::GetExamResult (unsigned examSubjectNameHash) const
{
    return examsResults_.at (examSubjectNameHash);
}

void Enrollee::SetExamResult (unsigned examSubjectNameHash, unsigned examResult)
{
    examsResults_ [examSubjectNameHash] = examResult;
}

bool Enrollee::HasMoreChoises () const
{
    return currentChoiseIndex_ < choises_.size ();
}

unsigned Enrollee::GetCurrentChoiseIndex () const
{
    return currentChoiseIndex_;
}

void Enrollee::IncreaseChoiceIndex ()
{
    currentChoiseIndex_++;
}

void Enrollee::RefreshChoiseIndex ()
{
    currentChoiseIndex_ = 0;
}

unsigned Enrollee::GetChoisesCount () const
{
    return choises_.size ();
}

EnrolleeChoise Enrollee::GetCurrentChoise () const
{
    if (HasMoreChoises ())
    {
        return choises_ [currentChoiseIndex_];
    }
    else
    {
        return EMPTY_ENROLLEE_CHOISE;
    }
}

EnrolleeChoise Enrollee::GetChoiseByIndex (unsigned index) const
{
    if (index < choises_.size ())
    {
        return choises_ [index];
    }
    else
    {
        return EMPTY_ENROLLEE_CHOISE;
    }
}

void Enrollee::AddChoiseToBack (const EnrolleeChoise &choise)
{
    choises_.push_back (choise);
}

void Enrollee::RemoveChoiseByIndex (unsigned index)
{
    choises_.erase (choises_.begin () + index);
}

void Enrollee::SwapChoisesAtIndexes (unsigned firstIndex, unsigned secondIndex)
{
    std::iter_swap (choises_.begin () + firstIndex, choises_.begin () + secondIndex);
}
}
