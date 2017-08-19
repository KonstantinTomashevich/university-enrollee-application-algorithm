#pragma once
#include <map>
#include <vector>
#include <string>

#include <UEAA/Core/Enrollee/StudyForm.hpp>
#include <UEAA/Core/Enrollee/EnrolleeChoice.hpp>
#include <UEAA/Utils/ReferenceCounted.hpp>

namespace UEAA
{
class Enrollee : public ReferenceCounted
{
public:
    Enrollee (const std::string &passportSeries, const std::string &passportNumber);
    virtual ~Enrollee ();

    unsigned GetId () const;
    const std::string &GetPassportSeries () const;
    const std::string &GetPassportNumber () const;

    unsigned char GetExamResult (unsigned examSubjectNameHash) const;
    void SetExamResult (unsigned examSubjectNameHash, unsigned char examResult);

    bool HasMoreChoices () const;
    unsigned GetCurrentChoiceIndex () const;
    void IncreaseChoiceIndex ();
    void RefreshChoiceIndex ();

    unsigned GetChoicesCount () const;
    const std::vector <EnrolleeChoice> &GetChoices () const;

    EnrolleeChoice GetCurrentChoice () const;
    EnrolleeChoice GetChoiceByIndex (unsigned index) const;

    void AddChoiceToBack (const EnrolleeChoice &choice);
    void RemoveChoiceByIndex (unsigned index);
    void SwapChoicesAtIndexes (unsigned firstIndex, unsigned secondIndex);

    EnrolleeChoice GetLastUpdateResult () const;
    void SetLastUpdateResult (const EnrolleeChoice &lastUpdateResult);

    unsigned char GetCertificateMark (unsigned subjectNameHash) const;
    void SetCertificateMark (unsigned subjectNameHash, unsigned char mark);

    float GetCertificateMedianMark () const;
    void CalculateCertificateMedianMark ();

    bool HasSchoolGoldMedal () const;
    void SetHasSchoolGoldMedal (bool hasSchoolGoldMedal);

private:
    unsigned id_;
    std::string passportSeries_;
    std::string passportNumber_;

    /// Exams results map. Key is exam subject name hash. Results will be in range (0, 100].
    std::map <unsigned, unsigned char> examsResults_;
    unsigned currentChoiceIndex_;
    std::vector <EnrolleeChoice> choices_;
    EnrolleeChoice lastUpdateResult_;

    /// School education certificate marks. Key is school subject name hash. Marks will be in range (0, 10].
    std::map <unsigned, unsigned char> certificateMarks_;
    float certificateMedianMark_;
    bool hasSchoolGoldMedal_;
};
}
