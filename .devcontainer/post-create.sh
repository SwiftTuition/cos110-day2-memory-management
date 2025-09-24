#!/bin/bash

# Post-create script for COS110 Day 2 Project
echo "🍭 Setting up the Yorozuya Memory Management Environment..."

# Update system packages
sudo apt-get update -y

# Install essential C++ development tools
sudo apt-get install -y \
    build-essential \
    g++ \
    make \
    valgrind \
    gdb \
    tree \
    curl \
    wget \
    zip \
    unzip

# Install Node.js for Gemini CLI
curl -fsSL https://deb.nodesource.com/setup_18.x | sudo -E bash -
sudo apt-get install -y nodejs

# Install Gemini CLI globally
echo "📡 Installing Gemini CLI for AI assistance..."
sudo npm install -g @google-ai/generativelanguage

# Create a simple script to install Gemini CLI properly
cat > /tmp/install_gemini.sh << 'EOF'
#!/bin/bash
# Install Google AI Studio CLI
curl -sS https://storage.googleapis.com/ai-platform-public/google-cloud-ai-platform/bin/linux-amd64/google-cloud-ai-platform > /tmp/google-cloud-ai-platform
sudo chmod +x /tmp/google-cloud-ai-platform
sudo mv /tmp/google-cloud-ai-platform /usr/local/bin/gai

# Alternative: Install using pip if available
pip3 install google-generativeai 2>/dev/null || echo "Note: Python Gemini client installation skipped"
EOF

chmod +x /tmp/install_gemini.sh
/tmp/install_gemini.sh

# Set up aliases for convenience
echo 'alias run="make run"' >> ~/.zshrc
echo 'alias test-basic="make check-basic"' >> ~/.zshrc
echo 'alias test-memory="make check-memory"' >> ~/.zshrc
echo 'alias test-all="make check-full"' >> ~/.zshrc

# Make sure the workspace has proper permissions
sudo chown -R vscode:vscode /workspaces

# Display welcome message
echo ""
echo "🎌 Welcome to the Yorozuya Memory Management Lab! 🎌"
echo ""
echo "Available commands:"
echo "  make run           - Compile and run your program"
echo "  make check-basic   - Test basic functionality"
echo "  make check-memory  - Check for memory leaks"
echo "  make check-full    - Complete test suite"
echo ""
echo "AI Assistant setup:"
echo "  Run './scripts/setup_gemini.sh' to configure Gemini CLI"
echo ""
echo "May the memory management force be with you! 🚀"
echo ""