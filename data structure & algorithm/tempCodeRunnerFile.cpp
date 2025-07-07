đọc các số từ các dòng còn lại vào mảng 2 chiều
        string line; 
        while (getline(inFile, line))
        {
            if (line.empty() || line == "\n")
                continue;
            vector<int> row; // hàng trong mảng 2 chiều
            stringstream ss(line);
            int num;
            while (ss >> num)
            {
                if (num)
                    tongbac++;
                row.push_back(num);
            }
            if (!row.empty())
                a.push_back(row);
        }
        inFile.close();
        if (t == 1)
        {
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (a[i][j])
                        cnt++;
                }
                outFile << cnt << " ";
            }
        }
        else if (t == 2)
        {
            outFile << n << " " << tongbac/2 << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[i][j])
                        outFile << i + 1 << " " << j + 1 << endl;
                }
            }
        }
        outFile.close();