import random

# Function to generate random responses
def get_random_response(responses):
    return random.choice(responses)

# Main function
def main():
    # Define some responses
    responses = [
        "Hello!",
        "Hi there!",
        "How can I help you?",
        "Nice to meet you!",
        "What's up?",
        "I'm just a simple chatbot.",
        "I'm sorry, I don't understand.",
        "Could you please rephrase that?",
        "Let me think about that for a moment...",
        "I'm not sure I can help with that.",
        "That's an interesting question!",
        "Sorry, I didn't catch that.",
        "I'm here to assist you!",
        "I'm sorry, I cannot provide an answer to that."
    ]

    print("Hello! I'm a chatbot. How can I help you today?")

    while True:
        user_input = input("> ").lower()

        # Check for quit command
        if user_input == "quit":
            print("Goodbye! Have a great day!")
            break

        # Get a random response
        response = get_random_response(responses)
        print(response)

if __name__ == "__main__":
    main()
