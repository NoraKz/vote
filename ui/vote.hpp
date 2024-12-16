#include <string>

namespace ui {
    std::string VoteHTML = R"HTML(
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>幸运学生抽选系统</title>
    <link href="https://unpkg.com/layui@2.9.20/dist/css/layui.css" rel="stylesheet">
    <style>
        body {
            background: linear-gradient(135deg, #1a2a6c, #b21f1f, #fdbb2d);
            min-height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .lottery-container {
            background-color: rgba(255, 255, 255, 0.1);
            backdrop-filter: blur(10px);
            border-radius: 20px;
            box-shadow: 0 8px 32px 0 rgba(31, 38, 135, 0.37);
            padding: 40px;
            width: 80%;
            max-width: 800px;
        }
        .lottery-title {
            color: #ffffff;
            text-align: center;
            font-size: 36px;
            margin-bottom: 40px;
            text-shadow: 2px 2px 4px rgba(0,0,0,0.5);
            font-weight: 300;
            letter-spacing: 2px;
        }
        .lottery-result {
            background-color: rgba(255, 255, 255, 0.2);
            border-radius: 15px;
            padding: 30px;
            margin-top: 40px;
            text-align: center;
            font-size: 24px;
            color: #ffffff;
            display: none;
            transition: all 0.5s ease;
        }
        .back-btn {
            position: fixed;
            top: 20px;
            left: 20px;
            z-index: 1000;
        }
        .layui-form-label {
            color: #ffffff;
        }
        .layui-input, .layui-select {
            background-color: rgba(255, 255, 255, 0.2) !important;
            border: none !important;
            color: #ffffff !important;
        }
        .layui-input:focus, .layui-select:focus {
            box-shadow: 0 0 10px rgba(255, 255, 255, 0.5);
        }
        .layui-form-select dl {
            background-color: rgba(26, 42, 108, 0.9);
            color: #ffffff;
        }
        .layui-btn {
            background: linear-gradient(45deg, #1a2a6c, #b21f1f);
            border: none;
            transition: all 0.3s ease;
        }
        .layui-btn:hover {
            transform: translateY(-3px);
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.3);
        }
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(20px); }
            to { opacity: 1; transform: translateY(0); }
        }
        .fade-in {
            animation: fadeIn 0.5s ease-out;
        }
    </style>
</head>
<body>
  <script src="https://unpkg.com/layui@2.9.20/dist/layui.js"></script>

    <button class="layui-btn layui-btn-primary layui-btn-sm back-btn" onclick="window.changeToIndex()">
        <i class="layui-icon layui-icon-left"></i> 返回
    </button>

    <div class="lottery-container fade-in">
        <h1 class="lottery-title">幸运学生抽选系统</h1>
        <form class="layui-form">
            <div class="layui-form-item">
                <label class="layui-form-label">选择班级</label>
                <div class="layui-input-block">
                    <select name="class" lay-filter="classSelect" id="classSelect" lay-verify="required">
                        <option value="">请选择班级</option>
                    </select>
                </div>
            </div>
            <div class="layui-form-item">
                <label class="layui-form-label">抽取人数</label>
                <div class="layui-input-block">
                    <input type="number" name="count" lay-verify="required|number|min1" placeholder="请输入抽取人数" autocomplete="off" class="layui-input">
                </div>
            </div>
            <div class="layui-form-item">
                <div class="layui-input-block">
                    <button class="layui-btn layui-btn-lg layui-btn-fluid" lay-submit lay-filter="formSubmit">开始抽选</button>
                </div>
            </div>
        </form>

        <div id="lotteryResult" class="lottery-result"></div>
    </div>

    <script>
        layui.use(['form', 'layer'], function(){
            var form = layui.form;
            var layer = layui.layer;
            var $ = layui.$;

            // 获取班级列表并填充下拉框
            window.getClass().then(function(classes) {
                var select = $('#classSelect');
                classes.data.forEach(function(cls) {
                    select.append(new Option(cls, cls));
                });
                form.render('select');
            });

            // 表单提交
            form.on('submit(formSubmit)', function(data){
                var className = data.field.class;
                var count = parseInt(data.field.count);

                if (!className) {
                    layer.msg('请选择班级', {icon: 2});
                    return false;
                }

                // 显示加载动画
                var loadIndex = layer.load(2, {shade: [0.3, '#000']});

                // 调用抽取API
                window.getRandomStudents(className, count).then(function(students) {
                    // 关闭加载动画
                    layer.close(loadIndex);

                    // 显示抽奖结果
                    var resultHtml = '<h2 style="margin-bottom: 20px;">抽选结果</h2>';
                    students.data.forEach(function(student, index) {
                        resultHtml += '<p class="fade-in" style="animation-delay: ' + (index * 0.2) + 's">' + 
                                      student.name + ' (' + student.sex + ')</p>';
                    });

                    $('#lotteryResult').html(resultHtml).slideDown({
                        duration: 800,
                        easing: 'easeOutBounce'
                    });

                    // 添加抽奖动画效果
                    $('html, body').animate({
                        scrollTop: $("#lotteryResult").offset().top
                    }, 1000, 'easeInOutQuart');
                });

                return false;
            });

            // 自定义验证规则
            form.verify({
                min1: function(value){
                    if(value < 1){
                        return '抽取人数必须大于等于1';
                    }
                }
            });
        });
    </script>
</body>
</html>
)HTML";
}