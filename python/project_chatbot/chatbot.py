import pandas as pd
import re
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression

# Đọc dữ liệu từ Excel
df = pd.read_excel("Book1.xlsx")

# Dùng patterns để train NLP
X = df["pattern"].astype(str).values
y = df["intent"].values

# Vector hóa dữ liệu
vectorizer = TfidfVectorizer()
X_vec = vectorizer.fit_transform(X)

# Train mô hình phân loại intent
model = LogisticRegression()
model.fit(X_vec, y)

# Hàm dự đoán intent
def detect_intent(user_input):
    user_vec = vectorizer.transform([user_input])
    pred_intent = model.predict(user_vec)[0]
    return pred_intent

# Hàm lấy năm từ câu hỏi
def extract_year(user_input):
    match = re.search(r"\b(20\d{2})\b", user_input)
    return int(match.group(1)) if match else None

# Hàm trả lời
def chatbot_response(user_input):
    intent = detect_intent(user_input)
    year = extract_year(user_input)

    if intent == "hocphi":
        if year:  # Nếu có năm
            result = df[(df["intent"] == "hocphi") & (df["year"] == year)]
            if not result.empty:
                return result.iloc[0]["response"]
            else:
                return f"Xin lỗi, hiện chưa có dữ liệu học phí cho năm {year}."
        else:
            return "Bạn muốn hỏi học phí năm nào? (VD: 2023, 2024, 2025)"
    else:
        # Lấy câu trả lời đầu tiên của intent đó
        result = df[df["intent"] == intent]
        if not result.empty:
            return result.iloc[0]["response"]
        else:
            return "Xin lỗi, tôi chưa hiểu câu hỏi của bạn."

# Vòng lặp chatbot
print("Chatbot tuyển sinh PTIT (gõ 'exit' để thoát)\n")
while True:
    user_input = input("Bạn: ")
    if user_input.lower() == "exit":
        print("Chatbot: Tạm biệt!")
        break
    print("Chatbot:", chatbot_response(user_input))
