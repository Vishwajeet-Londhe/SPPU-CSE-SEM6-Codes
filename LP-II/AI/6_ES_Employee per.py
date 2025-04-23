def evaluate_employee():
    print("=== Expert System: Employee Performance Evaluation ===")
    
    name = input("Enter Employee Name: ")
    role = input("Enter Role/Department: ")
    
    print("\nRate the following on a scale of 1 (Poor) to 5 (Excellent):")
    teamwork = int(input("Teamwork: "))
    punctuality = int(input("Punctuality: "))
    task_completion = int(input("Task Completion: "))
    communication = int(input("Communication Skills: "))
    problem_solving = int(input("Problem Solving: "))
    leadership = int(input("Leadership (if applicable, else rate as 3): "))

    total_score = teamwork + punctuality + task_completion + communication + problem_solving + leadership
    average_score = total_score / 6

    if average_score >= 4.5:
        remark = "Outstanding"
        suggestion = "Keep up the great work. Consider for leadership roles or promotions."
    elif average_score >= 3.5:
        remark = "Good"
        suggestion = "Consistent performance. Minor improvements will boost further."
    elif average_score >= 2.5:
        remark = "Average"
        suggestion = "Needs improvement in some areas. Consider targeted training."
    else:
        remark = "Below Average"
        suggestion = "Immediate attention needed. Schedule a performance review and support plan."

    print("\n=== Performance Report ===")
    print(f"Employee Name: {name}")
    print(f"Department/Role: {role}")
    print(f"Average Score: {average_score:.2f}/5")
    print(f"Performance Remark: {remark}")
    print(f"Recommendation: {suggestion}")


if __name__ == "__main__":
    evaluate_employee() 