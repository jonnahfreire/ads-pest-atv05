

def get_notes(notes_amount: int) -> list:
    if notes_amount is None:
        return []

    notes = []
    for i in range(1, notes_amount+1):
        note = float(input(f"Informe a {i}ª nota: "))
        notes.append(note)
    return notes


def get_average(notes: list) -> float:
    if len(notes) > 0:
        average = "{:.2f}".format(sum(notes) / len(notes))
        return float(average)
    return 0


def get_student_situation(average: float) -> str:
    if average >= 9:
        return "Aluno aprovado com Louvor!"
    elif average >= 7 and average < 9:
        return "Aluno aprovado!"
    elif average >= 4 and average < 7:
        return "Aluno ficou de avaliação final!"
    return "Aluno Reprovado!"


def main():
    notes_amount = int(input("Informe a quantidade de notas: "))
    notes = get_notes(notes_amount)
    average = get_average(notes)
    situation = get_student_situation(average)
    print("-"*40+f"\n{situation}")


def test() -> None:
    average_test()
    get_notes_test()
    get_student_situation_test()


def average_test():
    if get_average([]) == 0:
        print("get_average([]) -> 0 : OK")
    else:
        print("get_average([]) -> 0 : FAIL")

    if get_average([6.5, 7, 5]) == 6.17:
        print("get_average([6.5, 7, 5]) -> 6.17 : OK")
    else:
        print("get_average([6.5, 7, 5]) -> 6.17 : FAIL")


def get_notes_test():
    if get_notes(0) == []:
        print("get_notes(0) -> [] : OK")
    else:
        print("get_notes(0) -> [] : FAIL")

    if len(get_notes(3)) == 3:
        print("len(get_notes(3)) -> 3 : OK")
    else:
        print("len(get_notes(3)) -> 3 : FAIL")


def get_student_situation_test():
    if get_student_situation(0) == "Aluno Reprovado!":
        print("get_student_situation(0) -> Aluno Reprovado! : OK")
    else:
        print("get_student_situation(0) -> Aluno Reprovado! : FAIL")

    if get_student_situation(6.17) == "Aluno ficou de avaliação final!":
        print(
            "get_student_situation(6.17) -> Aluno ficou de avaliação final! : OK")
    else:
        print(
            "get_student_situation(6.17) -> Aluno ficou de avaliação final! : FAIL")


if __name__ == "__main__":
    test()
    # main()
