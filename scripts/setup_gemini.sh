#!/bin/bash

# 🤖 Gemini AI Assistant Setup Script
# "AI assistance? Great! Now even computers can help us avoid work!" - Gintoki

echo "🤖 Setting up Gemini AI Assistant for COS110 Day 2..."
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Check if we're in a Codespaces environment
if [ -n "$CODESPACES" ]; then
    echo -e "${CYAN}📡 Detected GitHub Codespaces environment${NC}"
else
    echo -e "${YELLOW}⚠️  Running in local environment${NC}"
fi

echo ""
echo -e "${PURPLE}🍭 Welcome to the Yorozuya AI Setup!${NC}"
echo -e "${YELLOW}Gintoki: 'An AI assistant? Does it work for free?'${NC}"
echo -e "${BLUE}Shinpachi: 'It's here to help you learn, not do the work for you!'${NC}"
echo -e "${RED}Kagura: 'Can it cook? No? Then what's the point, aru?'${NC}"
echo ""

# Function to install Gemini CLI via different methods
install_gemini_cli() {
    echo -e "${CYAN}📦 Installing Gemini CLI...${NC}"

    # Method 1: Try to install via pip
    if command -v pip3 >/dev/null 2>&1; then
        echo -e "${BLUE}🐍 Installing Google Generative AI Python package...${NC}"
        pip3 install google-generativeai --user

        # Create a simple Python wrapper script
        cat > /usr/local/bin/gemini-cli << 'EOF'
#!/usr/bin/env python3
import sys
import os
import google.generativeai as genai
import argparse

def main():
    parser = argparse.ArgumentParser(description='Gemini CLI for COS110')
    parser.add_argument('prompt', help='Your question or code to analyze')
    parser.add_argument('--api-key', help='Your Gemini API key')

    args = parser.parse_args()

    # Check for API key
    api_key = args.api_key or os.environ.get('GEMINI_API_KEY')
    if not api_key:
        print("❌ No API key provided. Set GEMINI_API_KEY environment variable or use --api-key")
        print("🔑 Get your API key from: https://makersuite.google.com/app/apikey")
        return 1

    try:
        genai.configure(api_key=api_key)
        model = genai.GenerativeModel('gemini-pro')

        # Load the instructional prompt template
        with open('/workspaces/COS110_Day2_Project/scripts/gemini_prompt_template.txt', 'r') as f:
            template = f.read()

        full_prompt = template.replace("{{USER_QUESTION}}", args.prompt)

        response = model.generate_content(full_prompt)
        print(response.text)

    except Exception as e:
        print(f"❌ Error: {e}")
        return 1

if __name__ == "__main__":
    main()
EOF

        chmod +x /usr/local/bin/gemini-cli
        echo -e "${GREEN}✅ Gemini CLI installed successfully${NC}"
    else
        echo -e "${YELLOW}⚠️  pip3 not available, trying alternative method...${NC}"

        # Method 2: Create a simple curl-based wrapper
        cat > /usr/local/bin/gemini-cli << 'EOF'
#!/bin/bash
# Simple Gemini API wrapper using curl

if [ $# -eq 0 ]; then
    echo "Usage: gemini-cli \"your question here\""
    echo "Set GEMINI_API_KEY environment variable first"
    echo "Get your API key from: https://makersuite.google.com/app/apikey"
    exit 1
fi

if [ -z "$GEMINI_API_KEY" ]; then
    echo "❌ GEMINI_API_KEY environment variable not set"
    echo "🔑 Get your API key from: https://makersuite.google.com/app/apikey"
    echo "Then run: export GEMINI_API_KEY=your_api_key_here"
    exit 1
fi

PROMPT="$1"
TEMPLATE=$(cat /workspaces/COS110_Day2_Project/scripts/gemini_prompt_template.txt)
FULL_PROMPT="${TEMPLATE//\{\{USER_QUESTION\}\}/$PROMPT}"

curl -s -X POST "https://generativelanguage.googleapis.com/v1/models/gemini-pro:generateContent?key=$GEMINI_API_KEY" \
     -H "Content-Type: application/json" \
     -d "{\"contents\":[{\"parts\":[{\"text\":\"$FULL_PROMPT\"}]}]}" \
     | jq -r '.candidates[0].content.parts[0].text // "Error processing request"'
EOF

        chmod +x /usr/local/bin/gemini-cli
        echo -e "${GREEN}✅ Basic Gemini CLI installed${NC}"
    fi
}

# Install jq for JSON processing (needed for curl method)
if ! command -v jq >/dev/null 2>&1; then
    echo -e "${BLUE}📦 Installing jq for JSON processing...${NC}"
    sudo apt-get update -qq && sudo apt-get install -y jq
fi

# Install the Gemini CLI
install_gemini_cli

echo ""
echo -e "${GREEN}🎉 Setup complete!${NC}"
echo ""
echo -e "${PURPLE}📚 How to use your AI assistant:${NC}"
echo ""
echo -e "${CYAN}1. Get your API key:${NC}"
echo "   Visit: https://makersuite.google.com/app/apikey"
echo "   Sign in with your Google account"
echo "   Click 'Create API Key' and copy the key"
echo ""
echo -e "${CYAN}2. Set your API key:${NC}"
echo "   export GEMINI_API_KEY=your_api_key_here"
echo ""
echo -e "${CYAN}3. Ask for help:${NC}"
echo "   gemini-cli \"Why is my code crashing?\""
echo "   gemini-cli \"How do I fix memory leaks?\""
echo "   gemini-cli \"What does this error mean: segmentation fault?\""
echo ""
echo -e "${YELLOW}📝 Example usage:${NC}"
echo "   gemini-cli \"My YorozuyaManager constructor crashes when I create an object. Here's my code: [paste code]\""
echo ""
echo -e "${BLUE}💡 Pro tips:${NC}"
echo "   - Include your error messages in the question"
echo "   - Paste relevant code snippets"
echo "   - Ask about specific concepts you don't understand"
echo "   - The AI will guide you toward solutions, not give answers directly"
echo ""
echo -e "${RED}⚠️  Remember:${NC}"
echo "   - This assistant helps you LEARN, not complete the work for you"
echo "   - Always understand the explanations, don't just copy code"
echo "   - Use it when you're stuck, not as a shortcut"
echo ""
echo -e "${PURPLE}🎌 The Yorozuya Philosophy:${NC}"
echo -e "${YELLOW}Gintoki: 'Even if you have help, you still gotta do the work yourself!'${NC}"
echo -e "${BLUE}Shinpachi: 'Understanding is more important than just getting the right answer!'${NC}"
echo -e "${RED}Kagura: 'If you don't learn it properly, you'll be hungry for knowledge forever, aru!'${NC}"
echo ""
echo -e "${GREEN}Happy coding! 🚀${NC}"