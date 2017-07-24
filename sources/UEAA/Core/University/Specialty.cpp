#include "Specialty.hpp"
#include <UEAA/Core/Enrollee/Enrollee.hpp>

namespace UEAA
{
Specialty::Specialty (unsigned id) :
    ReferenceCounted (),
    id_ (id),
    requiredExams_ (),
    marksInCertificatePriority_ (),

    enrolleesInFreeForm_ (),
    enrolleesInPaidForm_ (),

    maxEnrolleesInFreeForm_ (0),
    maxEnrolleesInPaidForm_ (0)
{

}

Specialty::~Specialty ()
{

}

unsigned Specialty::GetId () const
{
    return id_;
}

const std::vector <std::vector <unsigned> > &Specialty::GetRequiredExams() const
{
    return requiredExams_;
}

void Specialty::SetRequiredExams (const std::vector <std::vector <unsigned> > &requiredExams)
{
    requiredExams_ = requiredExams;
}

const std::vector <unsigned> &Specialty::GetMarksInCertificatePriority () const
{
    return marksInCertificatePriority_;
}

void Specialty::SetMarksInCertificatePriority (const std::vector <unsigned> &marksInCertificatePriority)
{
    marksInCertificatePriority_ = marksInCertificatePriority;
}

const std::vector <Enrollee *> &Specialty::GetEnrolleesInFreeForm () const
{
    return enrolleesInFreeForm_;
}

const std::vector <Enrollee *> &Specialty::GetEnrolleesInPaidForm () const
{
    return enrolleesInPaidForm_;
}

void Specialty::AddEnrollee (Enrollee *enrollee)
{
    // TODO: Implement.
}

std::vector <Enrollee *> Specialty::RemoveExcessEnrollees ()
{
    std::vector <Enrollee *> excessEnrollees;
    GetExcessEnrollees (excessEnrollees, STUDY_FORM_FREE);
    GetExcessEnrollees (excessEnrollees, STUDY_FORM_PAID);

    enrolleesInFreeForm_.erase (enrolleesInFreeForm_.begin () + maxEnrolleesInFreeForm_, enrolleesInFreeForm_.end () - 1);
    enrolleesInPaidForm_.erase (enrolleesInPaidForm_.begin () + maxEnrolleesInPaidForm_, enrolleesInPaidForm_.end () - 1);
    return excessEnrollees;
}

unsigned Specialty::GetMaxEnrolleesInFreeForm () const
{
    return maxEnrolleesInFreeForm_;
}

void Specialty::SetMaxEnrolleesInFreeForm (unsigned maxEnrolleesInFreeForm)
{
    maxEnrolleesInFreeForm_ = maxEnrolleesInFreeForm;
}

unsigned Specialty::GetMaxEnrolleesInPaidForm () const
{
    return maxEnrolleesInPaidForm_;
}

void Specialty::SetMaxEnrolleesInPaidForm (unsigned maxEnrolleesInPaidForm)
{
    maxEnrolleesInPaidForm_ = maxEnrolleesInPaidForm;
}

void Specialty::GetExcessEnrollees (std::vector <Enrollee *> &output, StudyForm studyForm) const
{
    std::vector <Enrollee *> enrollees = (studyForm == STUDY_FORM_FREE) ? enrolleesInFreeForm_ : enrolleesInPaidForm_;
    unsigned maxEnrollees = (studyForm == STUDY_FORM_FREE) ? maxEnrolleesInFreeForm_ : maxEnrolleesInPaidForm_;

    if (enrollees.size () > maxEnrollees)
    {
        for (auto iterator = enrollees.cbegin () + maxEnrollees;
             iterator != enrollees.cend (); iterator++)
        {
            output.push_back (*iterator);
        }
    }
}
}