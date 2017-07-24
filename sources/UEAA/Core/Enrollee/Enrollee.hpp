#pragma once
#include <map>
#include <vector>
#include <string>

#include <UEAA/Core/Enrollee/StudyForm.hpp>
#include <UEAA/Core/Enrollee/EnrolleeChoise.hpp>
#include <UEAA/Utils/ReferenceCounted.hpp>

namespace UEAA
{
class Enrollee : public ReferenceCounted
{
public:
    Enrollee (const std::string &passportSeries, const std::string &passportNumber);
    virtual ~Enrollee ();

    const std::string &GetPassportSeries () const;
    const std::string &GetPassportNumber () const;

    unsigned char GetExamResult (unsigned examSubjectNameHash) const;
    void SetExamResult (unsigned examSubjectNameHash, unsigned char examResult);

    bool HasMoreChoises () const;
    unsigned GetCurrentChoiseIndex () const;
    void IncreaseChoiceIndex ();
    void RefreshChoiseIndex ();

    unsigned GetChoisesCount () const;
    const std::vector <EnrolleeChoise> &GetChoices () const;

    EnrolleeChoise GetCurrentChoise () const;
    EnrolleeChoise GetChoiseByIndex (unsigned index) const;

    void AddChoiseToBack (const EnrolleeChoise &choise);
    void RemoveChoiseByIndex (unsigned index);
    void SwapChoisesAtIndexes (unsigned firstIndex, unsigned secondIndex);

    unsigned char GetCertificateMark (unsigned subjectNameHash) const;
    void SetCertificateMark (unsigned subjectNameHash, unsigned char mark);

    float GetCertificateMedianMark () const;
    void CalculateCertificateMedianMark ();

private:
    std::string passportSeries_;
    std::string passportNumber_;

    /// Exams results map. Key is exam subject name hash. Results will be in range (0, 100].
    std::map <unsigned, unsigned char> examsResults_;
    unsigned currentChoiseIndex_;
    std::vector <EnrolleeChoise> choises_;

    /// School education certificate marks. Key is school subject name hash. Marks will be in range (0, 10].
    std::map <unsigned, unsigned char> certificateMarks_;
    float certificateMedianMark_;
};
}