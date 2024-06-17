package com.zeroone.star.project.components.pdf;

import org.dromara.pdf.fop.handler.XEasyPdfTemplateHandler;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import java.io.ByteArrayOutputStream;
import java.util.Map;

/**
 * <p>
 * 描述：书写一个PDF组件，二次封装x-easy-pdf库的使用
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class PdfComponent {
    /**
     * fop配置文件路径
     */
    @Value("${pdf.conf}")
    private String configPath;
    /**
     * xsl-fo模板路径（目录）
     */
    @Value("${pdf.template}")
    private String templatePath;

    /**
     * 将数据生成到PDF文件中
     * @param templateFilename 使用模板名称
     * @param data             数据
     * @param outputPath       输出文件路径
     */
    public void generateToFile(String templateFilename, Map<String, Object> data, String outputPath) {
        // 设置模板路径
        XEasyPdfTemplateHandler.DataSource.Freemarker.setTemplatePath(templatePath);
        // 转换pdf
        XEasyPdfTemplateHandler.Template.build().setConfigPath(configPath).setDataSource(
                // 构建数据源
                XEasyPdfTemplateHandler.DataSource.Freemarker.build()
                        // 设置模板名称（模板路径下的文件名称）
                        .setTemplateName(templateFilename)
                        // 设置模板数据
                        .setTemplateData(data)
        ).transform(outputPath);
    }

    /**
     * 将数据生成到PDF文件中，对应无运行时数据模板
     * @param templateFilename 使用模板名称
     * @param outputPath       输出文件路径
     */
    public void generateToFile(String templateFilename, String outputPath) {
        generateToFile(templatePath + "/" + templateFilename, null, outputPath);
    }

    /**
     * 将数据生成到PDF输出流中
     * @param templateFilename 使用模板名称
     * @param data             数据
     * @param out              输出流
     */
    public void generateToStream(String templateFilename, Map<String, Object> data, ByteArrayOutputStream out) {
        // 设置模板路径
        XEasyPdfTemplateHandler.DataSource.Freemarker.setTemplatePath(templatePath);
        // 转换pdf
        XEasyPdfTemplateHandler.Template.build().setConfigPath(configPath).setDataSource(
                // 构建数据源
                XEasyPdfTemplateHandler.DataSource.Freemarker.build()
                        // 设置模板名称（模板路径下的文件名称）
                        .setTemplateName(templateFilename)
                        // 设置模板数据
                        .setTemplateData(data)
        ).transform(out);
    }

    /**
     * 将数据生成到PDF输出流中，对应无运行时数据模板
     * @param templateFilename 使用模板名称
     * @param out              输出流
     */
    public void generateToStream(String templateFilename, ByteArrayOutputStream out) {
        generateToStream(templatePath + "/" + templateFilename, null, out);
    }
}
